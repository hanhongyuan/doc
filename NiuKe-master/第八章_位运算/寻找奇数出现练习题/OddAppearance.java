import java.util.*;

//������� ��Ϊa^a=0 a^0=a ���Գ���ż���ε������ն�����0�� ֻʣ�������ε�����0��� ����Ȼ�����Ǹ������� ������������Ϻͽ�����
public class OddAppearance {
    public int findOdd(int[] A, int n) {
        int t=0;
        for(int i=0;i<n;i++){
        	t=t^A[i];
        }
        return t;
    }
}