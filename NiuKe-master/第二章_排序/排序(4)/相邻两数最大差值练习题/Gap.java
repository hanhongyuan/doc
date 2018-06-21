import java.util.*;
 
public class Gap {
 public int maxGap(int[] A, int n) {
        int max=A[0];
        int min=A[0];
        for (int i=0;i<n;i++){
            max=Math.max(A[i],max);
            min=Math.min(A[i],min);
        }
        if (max==min){
            return 0;
        }
 
        boolean [] hasnum=new boolean[n+1];//������ǵ�i��Ͱ���Ƿ���Ԫ��
        int [] maxs=new int[n+1];//��i��Ͱ�е����ֵ
        int [] mins=new int[n+1];//��i��Ͱ�е���Сֵ
        for (int i=0;i<n;i++){
            int bid=locationBucketIndex(A[i],n,min,max);//��λԪ�ؾ����ڼ���Ͱ��
            maxs[bid]=hasnum[bid]?Math.max(maxs[bid],A[i]):A[i];//�������ֵ
            mins[bid]=hasnum[bid]?Math.min(mins[bid],A[i]):A[i];//������Сֵ
            hasnum[bid]=true;
        }
        int result=0;
        int i=0;
        int first_max=0;//��һ���ǿ�Ͱ�����ֵ
        while (i<=n){//����Ѱ�ҵ�һ����Ԫ�ص�Ͱ�����ֵ
            if (hasnum[i]){
                first_max=maxs[i];
                break;
            }
            i++;
        }
        for (i=i+1;i<=n;i++){
            if (hasnum[i]){//�������Ͱ����Ԫ��
                result=Math.max(result,mins[i]-first_max);//��һ��Ͱ��Сֵ-ǰһ��Ͱ���ֵ
                first_max=maxs[i];//�������ֵΪ��ǰͰ���ֵ��Ȼ��i+1��ô�ͱ��ǰһ��Ͱ��
            }
        }
 
        return result;
    }
     
    private int locationBucketIndex(long num,long length,long min,long max){
        return (int) ((num-min)*length/(max-min));
    }
}