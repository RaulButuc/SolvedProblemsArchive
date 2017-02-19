import java.util.*;

public class CentSavings {

	Scanner in = new Scanner(System.in);

	public static void main(String[] args) {
		new CentSavings().go();
	}
	private void go() {
		int n = in.nextInt();
		int d = in.nextInt();
		int[] p = new int[n + 1];

		for(int i = 0; i < n; ++i) {
			p[i] = in.nextInt();
		}

		int[][] dp = new int[n + 1][d + 1];
		int total = 0;

		for(int i = n - 1; i >= 0; --i) {
			total += p[i];
			dp[i][0] = round(total);
		}

		for(int i = 1; i <= d; ++i) {
			for(int j = 0;j <= n; ++j) {
				int sum = 0;
				dp[j][i] = Integer.MAX_VALUE;

				for(int k = j; k <= n; ++k) {
					dp[j][i] = Math.min(dp[j][i], round(sum) + dp[k][i - 1]);
					sum += p[k];
				}
			}
		}
		System.out.println(dp[0][d]);
	}

	private int round(int total) {
		int mod = total % 10;

		if(mod < 5) {
			return total - mod;
		}

		return total - mod + 10;
	}
}
