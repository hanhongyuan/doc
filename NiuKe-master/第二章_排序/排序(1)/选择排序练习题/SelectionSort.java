import java.util.*;
 
public class SelectionSort {
    public int[] selectionSort(int[] A, int n) {
       int temp;
       for(int i=0;i<n/2;i++){//�Ż����ѡ������ ��ÿһ�α����Ĺ����а����ֵ����Сֵͬʱ���� ���Լһ���ʱ��
           int start=i;
           int end=n-i-1;
           int min_index=start;
           int max_index=start;
           
           for(int j=start;j<=end;j++){//ѡ����һ�α��������е�������Сֵ
               if(A[min_index]>A[j]){
                   min_index=j;
               }
               if(A[max_index]<A[j]){
                   max_index=j;
               }
           }
           
           if(min_index!=end&&max_index!=start){//���ֵ����Сֵ�����ڸ���λ���ϣ���������
               swap(A,min_index,start);
               swap(A,max_index,end);
           }else if(min_index==end&&max_index==start){//���ֵ����Сֵ�պô����ڶԷ���λ���� ��ֻ�������ߵ���һ�μ���
               swap(A,start,end);
           }else{//���ֵ������Сֵ��һ�����ڶԷ���λ���ϣ�����������Ҫ�� ����ᵼ�¸հ�������Сֵ��������Ӧλ�����ֱ����ߵ��������
               if(min_index==end){
                   swap(A,min_index,start);
                   swap(A,max_index,end);
               }
               if(max_index==start){
                   swap(A,max_index,end);
                   swap(A,min_index,start);
               }
           }
       }
       return A;
    }
    
    public void swap(int []A,int a,int b){
        int temp=A[a];
        A[a]=A[b];
        A[b]=temp;
    }
}