public class StandInLine {
	public int[] getWays(int n, int a, int b) {
		int answer1 = jiecheng(n, n) / 2;// ȫ����֮�� ��Ϊa��bֻ��������� Ҫ��a��b��� Ҫ��a��b�ұ�
											// ����ȡһ�뼴��
		int answer2 = jiecheng(n - 1, n - 1);// Ҫ������ �������һ����Ȼ�����n-1ȫ���м���
		int[] res = new int[2];
		res[0] = answer1;
		res[1] = answer2;
		return res;
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