public class Compare {

	/*
	 * ����������ۺ���⣺ a��b������ͬ�� diffabΪ0 sameabΪ1 ��ʱ��cs�ķ��� ��a����b csΪ1 ��ôreturnAΪ1
	 * returnBΪ0 �����ȷ a��b���Ų���ͬ�� diffabΪ1 sameabΪ0 ��ʱ��as�ķ��� ��aΪ����bΪ�� �ǽ���϶�Ϊa����b
	 * ��returnAΪ1 returnBΪ0 �����ȷ aΪ��bΪ�� �ǿ϶�b����a returnAΪ0 returnBΪ1 �����ȷ
	 */
	public int getMax(int a, int b) {
		int c = a - b;
		int as = sign(a);// a�ķ���λ 1Ϊ�� 0Ϊ��
		int bs = sign(b);// b�ķ���λ 1Ϊ�� 0Ϊ��
		int cs = sign(c);// ��ֵc�ķ���λ 1Ϊ�� 0Ϊ��

		int diffab = as ^ bs;// �ж�a��b�������ķ���λ�Ƿ���ͬ ��ͬΪ0 ����ͬΪ1
		int sameab = flip(diffab);// �ж�a��b�������ķ���λ�Ƿ���ͬ ��ͬΪ1����ͬΪ0

		int returnA = diffab * as + sameab * cs;
		int returnB = flip(returnA);

		return a * returnA + b * returnB;
	}

	// ��ȡ����λ���1������ٺ�1������
	public int sign(int num) {
		return flip(num >> 31 & 1);
	}

	// ��1����������
	public int flip(int n) {
		return (n ^ 1);
	}

	// ������ ���򵥵��ж�
	public int getMax1(int a, int b) {
		int c = a - b;
		int sca = sign(c);// ��a-b����0 scaΪ1 scbΪ0
		int scb = flip(sca);

		return sca * a + scb * b;
	}
}