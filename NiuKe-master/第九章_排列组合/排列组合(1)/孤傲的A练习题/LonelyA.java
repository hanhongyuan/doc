public class LonelyA {
	public int getWays(int n, int A, int b, int c) {
		int count1 = C(n - 3, 1) * jiecheng(n - 2, n - 2) * 2;//��A�ڿ�ͷ��ĩβʱ��������� ��A��ͷʱ ��Ϊ���������������� ����n-3������ѡһ��Ȼ��ʣ�µ�n-2��ȫ���� ��ĩβҲ��һ��
		int count2 = C(n - 3, 2) * jiecheng(n - 3, n - 3) * (n - 2) * 2;//��A���м��ʱ�� Ҫ��n-3������ѡ2����A���� Ȼ��ʣ�µ���ȫ���� ���������ֿ��Ե���λ������Ҫ����2 Ȼ���ٳ����м�ʣ�µ�n-2��λ�� ��Ϊÿ��λ�ö�һ��
		return count1 + count2;
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