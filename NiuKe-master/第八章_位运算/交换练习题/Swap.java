import java.util.*;

public class Swap {
	/*
	 *����˵����
	 *a=a^b
	 *b=a^b  ʽ�ӱ仯��: b=a^b^b ��Ϊ b^b=0 ���� b=a^0=a;
	 *a=a^b  ʽ�ӱ仯��: a=a^b^a ����a=b
	 */
    public int[] getSwap(int[] num) {
        num[0] = num[0]^num[1];
        num[1] = num[0]^num[1];
        num[0] = num[0]^num[1];
        return num;
    }
}