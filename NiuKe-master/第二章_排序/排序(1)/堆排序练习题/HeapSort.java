import java.util.*;
 
public class HeapSort {
    public int[] heapSort(int[] A, int n) {
        headsort(A,n);
        return A;
    }
    public void headAdjust(int []A,int parent,int length){
        int temp=A[parent];//��¼���ڵ�ֵ
        int children=parent*2+1;//ȡ���ӽڵ�����
        while(children<length){
            if(children+1<length&&A[children+1]>A[children]){//�����ǹ��������
                children++;//ȡ�������ӽڵ��������Ǹ�
            }
            if(temp>A[children]){//������ڵ���ں��ӽڵ� ���˳� �������ڵ���������
                break;
            }
	    //ѭ�����ӽڵ����
            A[parent]=A[children];
            parent=children;
            children=children*2+1;
        }
        A[parent]=temp;//������ĸ��ڵ�Żض�������
    }
    public void headsort(int []A,int n){
        for(int i=n/2;i>=0;i--){//������ʼ�� ��2/n��ʼ����������
           headAdjust(A,i,A.length);
        }
        for(int i=n-1;i>0;i--){//�ѶѶ�Ԫ��Ҳ�������ֵ�ŵ����Ȼ��ÿ�ν���һ�ζѵ���
            swap(A,0,i);
            headAdjust(A,0,i);
        }
    }
    public void swap(int []A,int a,int b){
        int temp=A[a];
        A[a]=A[b];
        A[b]=temp;
    }
}