import java.util.*;
import java.awt.*;

public class KnapsackCollection {
	Scanner in = new Scanner(System.in);
    
	public static void main(String[] args) {
		new KnapsackCollection().go();
	}
    
	private void go() {
		int n = in.nextInt(), s = in.nextInt(), t = in.nextInt();
		int[] k = new int[n];
		long[] ans = new long[n];
		long max = 0;
		long min = Long.MAX_VALUE;
        
        for (int i = 0; i < n; ++i) {
            k[i] = in.nextInt();
        }
        
		for (int i = 0; i < n; ++i) {
            long time = 0;
			Point pos = new Point(k[i], -1);
			TreeSet<Point> ts = new TreeSet<Point> (new Comparator<Point>() {
				public int compare(Point arg0, Point arg1) {
                    if (arg0.x != arg1.x) {
                        return arg0.x - arg1.x;
                    }
                    
					return arg0.y - arg1.y;
				}
			});
            
            for (int j = 0; j < n; ++j) {
                ts.add(new Point(k[j], j));
            }
            
			while (!ts.isEmpty()) {
				Point next = ts.higher(pos);
                
				if (next == null) {
					time += s - pos.x;
					pos.x = 0;
					continue;
				}
                
				time += next.x - pos.x;
				ts.remove(next);
				pos.x = (next.x + t) % s;
				time += t;
			}
            
			ans[i] = time;
		}
        
		TreeSet<Point> ts = new TreeSet<Point> (new Comparator<Point>() {
			public int compare(Point arg0, Point arg1) {
                if (arg0.x != arg1.x) {
                    return arg0.x - arg1.x;
                }
                
				return arg0.y - arg1.y;
			}
		});
        
		long num = 0;
        
        for (int j = 0; j < n; ++j) {
            ts.add(new Point(k[j], j));
        }
        
		for (int i = 0; i < s; ++i) {
            long time;
			Point on = ts.higher(new Point(i, -1));
            
            if (on != null) {
                time = on.x - i + ans[on.y];
            }
            else {
                time = s - i + ts.first().x + ans[ts.first().y];
            }
            
			max = Math.max(max, time);
			min = Math.min(min, time);
			num += time;
		}
        
		long gcd = greatestCommonDenominator(num, s);
		
        System.out.printf("%d\n%d\n%d/%d\n", min, max, num / gcd, s / gcd);
	}
    
	long greatestCommonDenominator(long a, long b) {
		while (b != 0) {
			long t = a % b;
			a = b;
			b = t;
		}
        
		return a;
	}
}