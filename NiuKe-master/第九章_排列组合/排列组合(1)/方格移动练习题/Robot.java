public class Robot {
	public int countWays(int x, int y) {// x��y�� ����������y-1�� ������x-1��
		return C(x - 1 + y - 1, x - 1);
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