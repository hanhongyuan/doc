package niuke;

// 01������ϰ��
public class Backpack {
	public int maxValue(int[] w, int[] v, int n, int cap) {
		int dp[][] = new int[n][cap + 1];// ��ʾ dp[i][j] ʹ��0..i��Ʒ���J���ص�����ֵ

		for (int i = 0; i <= cap; i++) {// ��ֵ��һ�� ʹ�õ�һ����Ʒ ֻ�е�j���ڵ�һ����Ʒ����ʱ�ſ���ʹ��
			if (w[0] <= i) {
				dp[0][i] = v[0];
			} else {
				dp[0][i] = 0;
			}
		}

		for (int i = 0; i < n; i++) {// ����Ϊ0ʱ ������μ�ֵ��Ϊ0
			dp[i][0] = 0;
		}

		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= cap; j++) {
				if (j >= w[i]) {// ������i����Ʒʱ ѡ��װ����߲�װ�� ȡ��ֵ�������� �ڱ�����������������
					dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
				} else {// �������ز�����װi��Ʒ ��ֱ�Ӹ�ֵ��װ��
					dp[i][j] = dp[i - 1][j];
				}
			}
		}

		return dp[n - 1][cap];
	}
}
