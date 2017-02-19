#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cassert>

using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef long long ll;
typedef complex<ll> point;
typedef complex<double> pointD;
typedef pair<double, double> pdd;

auto vs(const point &a, const point &b) -> ll {
    return imag(conj(a) * b);
}

auto vs(const pointD &a, const pointD &b) -> double {
    return imag(conj(a) * b);
}

auto ss(const point &a, const point &b) -> ll {
    return real(conj(a) * b);
}

auto ss(const pointD &a, const pointD &b) -> double {
    return real(conj(a) * b);
}

auto priam(point a, point b, point c) -> bool {
    return vs(c - a, b - a) == 0 && ss(a - c, b - c) < 0;
}

auto pret(point a, point b, point c, point d) -> bool {
    if (priam(a, b, c)) { return true; }
    if (priam(a, b, d)) { return true; }
    if (priam(c, d, a)) { return true; }
    if (priam(c, d, b)) { return true; }
    return vs(c - a, b - a) * vs(d - a, b - a) < 0 && vs(a - c, d - c) * vs(b - c, d - c) < 0;
}

auto angle(point x, point y) -> double {
    double r = acos(ss(x, y) / sqrt(ss(x, x)) / sqrt(ss(y, y)));
    return vs(x, y) < 0 ? -r : r;
}

auto angle(pointD x, pointD y) -> double {
    double dif = arg(x) - arg(y);
    if (dif < -M_PI) {
        dif += 2 * M_PI;
	}
    if (dif > M_PI) {
        dif -= 2 * M_PI;
	}
    return dif;
}

auto inside(point x, vector<point>& a, bool strict = true) -> bool {
    double uh = 0;
    rep(k, 0, a.size()) {
        if (priam(a[k], a[(k + 1) % a.size()], x))
            return !strict;
        uh += angle(a[k] - x, a[(k + 1) % a.size()] - x);
    }

    return fabs(uh) < 6 ? false : true;
}

auto main(int argc, char *argv[]) -> int {
    int n; scanf("%d", &n);
    vector<point> a(n);
    vector<pointD> ad(n);
    rep(i, 0, n) {
        int x, y;
        scanf("%d %d", &x, &y);
        ad[i] = pointD(x, y);
        x *= 2; y *= 2;
        a[i] = point(x, y);
    }

    int start = 0;
    rep(i, 1, n) {
		if (real(a[i]) < real(a[start]) || (real(a[i]) == real(a[start]) && imag(a[i]) < imag(a[start])) ) {
        	start = i;
		}
	}

    int p = (start + 1) % n, q = (start + n - 1) % n;
    pointD vp = ad[p] - ad[start], vq = ad[q] - ad[start];
    vp /= abs(vp); vq /= abs(vq);
    pointD origin = ad[start] + 5e-5 * (vp + vq);

    int m; scanf("%d", &m);
    rep(i, 0, m) {
        int x, y;
        scanf("%d %d", &x, &y);
        ad.push_back(pointD(x, y));
        x *= 2; y *= 2;
        a.push_back(point(x, y));
    }

    double d[n + m][n + m];
    double rot[n + m][n + m];
    rep(i, 0, n + m) {
		rep(j, 0, i) {
	        d[i][j] = d[j][i] = abs(ad[i] - ad[j]);
	        rot[i][j] = angle(ad[j] - origin, ad[i] - origin);
	        rot[j][i] = -rot[i][j];

	    }
	}
	rep(i, 0, n + m) {
		d[i][i] = 1e20;
	}

    vector<point> inner(a.begin(), a.begin() + n), outer(a.begin() + n, a.end());
    rep(i, 0, n + m) {
		rep(j, 0, i) {
	        bool ok = true;
	        
	        rep(k, 0, n + m) {
	            int l = k + 1;
				l = (k < n) ? l % n : (l - n) % m + n;

	            set<int> all = {i, j, k, l};
	            if (all.size() == 4 && pret(a[i], a[j], a[k], a[l])) {
	                ok = false;
				}
	        }

	        point mid = a[i] + a[j];
	        mid = point(real(mid) / 2, imag(mid) / 2);
	        if (ok && inside(mid, inner)) { ok = false; }
	        if (ok && !inside(mid, outer, false)) { ok = false; }
			
	        if (!ok) { d[i][j] = d[j][i] = 1e30; }
	    }
	}

    vector<vector<pdd> > dist(n + m);
    dist[start].push_back(pdd(0, 0));
    vector<int> seen(n + m);

    double res = 1e20;
    rep(iter, 0, 2 * (n + m)) {
        int mi = -1, mj = -1;
        rep(i, 0, n + m) {
			if (seen[i] < (int)dist[i].size()) {
            	if (mi == -1 || dist[i][seen[i]] < dist[mi][mj]) {
	                mi = i;
	                mj = seen[i];
				}
            }
		}
        
		if (dist[mi][mj].first > res) break;

        rep(j, 0, n + m) {
            pdd w = dist[mi][seen[mi]];
            w.first += d[mi][j];
            w.second += rot[mi][j];

            bool update = true;
            for (pdd &o : dist[j])
                if (abs(o.second - w.second) < 1e-6) {
                    if (o.first > w.first) o = w;
                    update = false;
                }

            if (update && (dist[j].size() < 2 || dist[j].back().first > w.first)) {
                dist[j].push_back(w);
			}

            sort(dist[j].begin(), dist[j].end());
            
			if (dist[j].size() > 2) {
				dist[j].resize(2);
			}
        }

        if (++seen[mi] == 2) {
            res = min(res, dist[mi][0].first + dist[mi][1].first);
            assert(abs(abs(dist[mi][0].second - dist[mi][1].second) - M_PI * 2) < 1e-7);
        }
    }

    cout.precision(15);
    cout << res << endl;
	
	return 0;
}
