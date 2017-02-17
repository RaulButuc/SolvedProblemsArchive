import java.util.*;

public class Indoorienteering {
	
	Scanner in = new Scanner(System.in);
    
	public static void main(String[] args) {
		new Indoorienteering().go();
	}
    
	private void go() {
		int n = in.nextInt();
		long l = in.nextLong();
		long[][] d = new long[n][n];
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = in.nextLong();
            }
        }
        
		if (n == 2) {
			System.out.printf("%s\n", d[0][1] + d[1][0] == l ? "possible" : "impossible");
			System.exit(0);
		}
        
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < 1 << (n - 2); ++j) {
                if (Integer.bitCount(j) == (n - 2) / 2 && j < (j ^ ((1 << (n - 2)) - 1))) {
                    int[] inn = new int[(n - 2) / 2], out = new int[n - 2 - (n - 2) / 2];
                    int inni = 0, outi = 0;
                    
                    for (int k = 1; k < n; k++) if (k != i) {
                        if (((j >> (k - (k > i ? 2 : 1))) & 1) == 1) {
                            inn[inni++] = k;
                        }
                        else {
                            out[outi++] = k;
                        }
                    }
                    
                    HashSet<Long> l1 = solve(inn, d, 0, i);
                    HashSet<Long> l2 = solve(out, d, i, 0);
                    
                    for (long ls : l1) {
                        if (l2.contains(l - ls)) {
                            System.out.println("possible");
                            System.exit(0);
                        }
                    }
                }
            }
		}
        
		System.out.println("impossible");
	}
    
	private HashSet<Long> solve(int[] inn, long[][] d, int f, int l) {
		HashSet<Long> r = new HashSet<Long>();
		
        if (inn.length == 0) {
			r.add(d[f][l]);
			return r;
		}
        
		do {
			long ans = 0;
			ans += d[f][inn[0]];
			ans += d[inn[inn.length - 1]][l];
			for (int i = 0; i < inn.length - 1; i++) ans += d[inn[i]][inn[i + 1]];
			r.add(ans);
		} while (nextPermutation(inn));
        
		return r;
	}
    
	public boolean nextPermutation(int[] in) {
		for (int i = in.length - 2; i >= 0; --i) {
            if ( in[i] < in[i + 1]) {
                for (int j = in .length - 1; j > i; --j) {
                    if ( in[j] > in[i]) {
                        int t = in[i];
                        in[i] = in[j];
                        in[j] = t;
                        break;
                    }
                }
                
                for (int j = i + 1; j < in.length - (j - i); ++j) {
                    int t = in[j];
                    in[j] = in[in.length - (j - i)];
                    in[in.length - (j - i)] = t;
                }
                
                return true;
            }
        }
        
		return false;
	}
	
}
