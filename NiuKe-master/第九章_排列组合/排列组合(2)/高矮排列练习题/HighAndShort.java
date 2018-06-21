public class HighAndShort {
	public int countWays(int n) {
		return C(n, n / 2) / (n / 2 + 1);
	}

	// Cmn��������� Cmn=m!/n!(m-n)!
	public int C(int m, int n) {
		return jiecheng(m, n) / jiecheng(n, n);
	}

	// ����n��time�ν׳�
	public int jiecheng(int n, int time) {
		int res = 1;
		for (int i = n; time > 0; i--) {
			res *= i;
			time--;
		}
		return res;
	}
}