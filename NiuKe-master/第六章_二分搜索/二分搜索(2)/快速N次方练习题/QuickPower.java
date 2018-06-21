public class QuickPower {
	public int getPower(int k, int N) {

		if (N == 0) {
			return 1;
		}
		long res = 1;
		long temp = k;
		for (int i = N; i > 0; i >>= 1) {// ����һλ
			if ((i & 1) != 0) {// λ���� ��������0 ˵����ʱi�Ķ�����ĩβΪ1 Ҫ���м���
				res *= temp;
			}
			temp = (temp * temp) % 1000000007;
			res = res % 1000000007;
		}

		return (int) res;
	}
}