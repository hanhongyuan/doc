package niuke;

//LCS��ϰ��
public class LCS {
	public int findLCS(String A, int n, String B, int m) {
		int dp[][] = new int[n][m];// dp[i][j] ���� A�ַ���0..i��B�ַ���0..j������������г���

		for (int i = 0; i < n; i++) {// ��ֵ��һ�� һ�����Ϻ�B��һ���ַ���ȵ� �ͺ��涼��ֵΪ1
			if (A.charAt(i) == B.charAt(0)) {
				dp[i][0] = 1;
				while (i < n) {
					dp[i][0] = 1;
					i++;
				}
				break;
			}
		}

		for (int i = 0; i < m; i++) {// ��ֵ��һ�� һ�����Ϻ�A��һ���ַ���ȵ� �ͺ��涼��ֵ1
			if (A.charAt(0) == B.charAt(i)) {
				dp[0][i] = 1;
				while (i < m) {
					dp[0][i] = 1;
					i++;
				}
				break;
			}
		}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				if (A.charAt(i) == B.charAt(j)) {// ��ʱi��j�ַ���� ������i-1 j-1�ַ���1
					dp[i][j] = dp[i - 1][j - 1] + 1;
				} else {
					dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);// ȡ�������
				}
			}
		}

		return dp[n - 1][m - 1];
	}
}
