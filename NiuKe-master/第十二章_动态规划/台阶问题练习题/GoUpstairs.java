package niuke;

//̨��������ϰ��
public class GoUpstairs {
	public int countWays(int n) {
		int dp[] = new int[n + 1];// dp[i] ��ʾ��i��̨�׵ķ�����

		dp[1] = 1;// ��ʼ��dp[1]��һ��̨�׾�һ�ַ���
		dp[2] = 2;// �϶���̨�׾�2�� һ����һ��̨�׻���һ����2��̨��

		for (int i = 3; i <= n; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
		}

		return dp[n];
	}
}
