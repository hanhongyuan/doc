import java.util.*;


/*
 * �����������������N���ε�N�����ϣ�ÿ�����Ͽ�����2���߷�ѡ������һ����2��n�η����߷�
 * Ȼ����ͷ�ĵ����ֻ��2�� ���Ǵ�Ҷ�˳ʱ���ߺ���ʱ���� ������ͷ�ĸ��ʾ��� �ܵ��߷�-2/�ܵ��߷�
 */
public class Ants {
    public int[] collision(int n) {
    	int fenmu=(int) Math.pow(2, n);
    	int fenzi=fenmu-2;
    	int yue=gcd(fenmu, fenzi);
    	fenmu=fenmu/yue;
    	fenzi=fenzi/yue;
    	int res[]=new int [2];
    	res[0]=fenzi;
    	res[1]=fenmu;
    	
    	return res;
    }
    


	// շת����������Լ�� Ҫ��m>n
	public int gcd(int m, int n) {
		while (true) {
			if ((m = m % n) == 0) {
				return n;
			}
			if ((n = n % m) == 0) {
				return m;
			}
		}
	}
}