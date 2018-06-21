package niuke;

//������С·������ϰ��
public class MinimumPath {
	public int getMin(int[][] map, int n, int m) {
		int dp[][] = new int[n][m];// dp[i][j] �����ߵ�i jλ�õ���С·����

		for (int i = 0; i < n; i++) {// ��ʼ����һ��
			dp[i][0] = i == 0 ? map[i][0] : map[i][0] + dp[i - 1][0];
		}

		for (int i = 0; i < m; i++) {// ��ʼ����һ��
			dp[0][i] = i == 0 ? map[0][i] : map[0][i] + dp[0][i - 1];
		}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				dp[i][j] = map[i][j] + Math.min(dp[i - 1][j], dp[i][j - 1]);// ѡ���Ϸ���������С��һ��
			}
		}

		return dp[n - 1][m - 1];
	}
}
