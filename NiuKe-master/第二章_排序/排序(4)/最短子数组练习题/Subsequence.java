import java.util.*;
 
public class Subsequence {
    public int shortestSubsequence(int[] A, int n) {
        int min=A[n-1];
        int max=A[0];
        int p=0,q=n-1;
        for (int i=0;i<n;i++){
            if (max>A[i]){//�����i������big�󣬸���big��ֱ��������bigС����¼�±ꡣ�±�����ͣ�������һ����bigС�����ϡ���ô�������̾����˴Ӵ�С�ٴ��м��δ���������ĩβ�����±�p
                p=i;
            }else {
                max=A[i];
            }
        }
        for (int i=n-1;i>=0;i--){
            if (min<A[i]){//�����n-i-1������smallС������small��ֱ��������small�󣬼�¼�±ꡣ�±�����ͣ�������һ����small������ϣ��������̾����˴�С������С���м��δ����Ŀ�ͷ�����±�q
                q=i;
            }else {
                min=A[i];
            }
        }
        if (p==0&&q==n-1)
            return 0;
 
        return p-q+1;
    }
}