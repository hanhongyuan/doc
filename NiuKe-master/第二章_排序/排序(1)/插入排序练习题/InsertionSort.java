import java.util.*;
 
public class InsertionSort {
    public int[] insertionSort(int[] A, int n) {
        int temp;
        for(int i=1;i<n;i++){
            int j=i;
            temp=A[j];//��¼��ǰ�ڵ�ֵ
            while(j>0&&temp<A[j-1]){//�ӵ�ǰ�ڵ㿪ʼ����ǰ����һ�β���������̲���ֵԪ��
                A[j]=A[j-1];
                j--;
            }
            A[j]=temp;//���ѽڵ�ֵ�Żؽ���������
        }
        return A;
    }
}