import java.util.*;
 
public class MergeSort {
    public int[] mergeSort(int[] A, int n) {
         mergePass(A,0,n-1);
         return A;
    }
    public void mergePass(int [] A,int left,int right){
       if(right>left){
            
            
           if(right-left<10){//Ԫ�ظ���С��һ������ʱ���ò������� �����Լ�ָ��
               insertSort(A,left,right);
           }
            
           int middle=(left+right)/2;
           mergePass(A,left,middle);
           mergePass(A,middle+1,right);
            
            
           if(A[middle]<=A[middle+1]){//������м�����ǰ���������Ѿ����� ������һ������ ����Ҫ�ٴν��е���
               return;
           }
            
           merge(A,left,right,middle);
       }
    }
    public void insertSort(int []A,int start,int end){
        int temp;
        for(int i=start;i<end;i++){
            int  j=i;
            while(j>start&&A[j]<A[j-1]){
                temp=A[start];
                A[start]=A[end];
                A[end]=temp;
                j--;
            }
        }
    }
    public void merge(int []A,int low,int high,int mid){
        int []temp=new int [high-low+1];//����һ����ʱ�ռ�������õ�Ԫ��
        int k=0;
        int i=low,j=mid+1;
        while(i<=mid&&j<=high){//��С��Ԫ�����ȷŵ�������
            if(A[i]>A[j]){
                temp[k++]=A[j++];
            }else{
                temp[k++]=A[i++];
            }
        }
        while(i<=mid){//��ʣ���Ԫ�ز���
            temp[k++]=A[i++];
        }
        while(j<=high){//ͬ��
            temp[k++]=A[j++];
        }
        for( k=0,i=low;i<=high;i++,k++){//����ú����·Ż�ԭ������ȥ
            A[i]=temp[k];
        }
    }
}