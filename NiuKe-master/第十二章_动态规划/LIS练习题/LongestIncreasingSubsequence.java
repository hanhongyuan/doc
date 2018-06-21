package niuke;

//LIS��ϰ��
public class LongestIncreasingSubsequence {
	public int getLIS(int[] A, int n) {
		int dp[] = new int[n];// dp[i] ��ʾ���һ���ַ�ΪA[i]ʱ������������еĳ���

		dp[0] = 1;

		int res = 0;
		for (int i = 1; i < n; i++) {

			int j = i;
			int max = 0;
			for (; j >= 0; j--) {// ÿ�δ�iλ����ǰ�����ҵ���iС��λ�� ȡ��Щλ���������г��������Ϊ��һ������
				if (A[j] < A[i] && dp[j] > max) {
					max = dp[j];
				}
			}
			dp[i] = max + 1;
			res = Math.max(dp[i], res);// ��¼�����������������������
		}

		return res;
	}
}
