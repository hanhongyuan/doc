import java.util.*;

/**
 * ��ˮ�س����㷨��
 * 1.����1-k����ʱ��ֱ�ӷ��������
 * 2.�����i����(��ʱi����k)��ʱ����k/i�ĸ��ʾ����Ƿ��i���������У������뻹Ҫ�ڴ���������ӵ�һ��
 * @author sony
 *
 */
public class Bag {
    private int [] selected = null;
    private static Random rand = new Random(12345);
    // ÿ����һ���򶼻�������������N��ʾ��i�ε���
    public int[] carryBalls(int N, int k) {
    	selected=new int [k];
    	if (N<=k) {
			selected[N-1]=N;
		}else {
		    int i=rand.nextInt(k);
            
            if(rand.nextInt(N)<k){//��������ĸ�����k/i
            selected[i]=N;
            }
		}
        return selected;
    }
}