import java.util.*;
 
public class CountingSort {
    public int[] countingSort(int[] A, int n) {
        int min=A[0];
        int max=A[0];
 
        for (int i=0;i<A.length;i++){//�ҵ����ֵ����Сֵ������ȷ�������С
            min=Math.min(min,A[i]);
            max=Math.max(max,A[i]);
        }
 
        int []temp=new int[max-min+1];//����һ���µ����飬��СΪlen
 
        for (int i=0;i<A.length;i++){//�����ָ�ֵ����������
            temp[A[i]-min]++;
        }
        int k=0;
        for (int i=0;i<temp.length;i++){//����˳�����ε�������
            while (temp[i]!=0){
                A[k]=i+min;
                k++;
                temp[i]--;
            }
        }
        return A;
    }
}