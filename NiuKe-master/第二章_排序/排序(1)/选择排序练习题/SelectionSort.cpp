#include <iostream>
using namespace std; 
 
  
class SelectionSort {
public:
    int* selectionSort(int* A, int n) {
         
        for(int i=0;i<n/2;i++)//�Ż����ѡ������ ��ÿһ�α����Ĺ����а����ֵ����Сֵͬʱ���� ���Լһ���ʱ��
        {
            int start=i;
            int end=n-i-1;
            int max,min;
            int s,e;
 
            max=start;
            min=start;
            s=start;
            e=end;
 
            for(;s<=e;s++)//ѡ����һ�α��������е�������Сֵ
            {
                if(A[s]>A[max])
                {
                    max=s;
                }
 
                if(A[s]<A[min])
                {
                    min=s;
                }
            }
             
             
            if(max!=start&&min!=end){//���ֵ����Сֵ�����ڸ���λ���ϣ���������
                 int temp=A[max];
                A[max]=A[end];
                A[end]=temp;
                 
                temp=A[min];
                A[min]=A[start];
                A[start]=temp;
            }
            else if(max==start&&min==end){//���ֵ����Сֵ�պô����ڶԷ���λ���� ��ֻ�������ߵ���һ�μ���
                int temp=A[start];
                A[start]=A[end];
                A[end]=temp;
                   
            }else{//���ֵ������Сֵ��һ�����ڶԷ���λ���ϣ�����������Ҫ�� ����ᵼ�¸հ�������Сֵ��������Ӧλ�����ֱ����ߵ��������
                if(max==start){
                    int temp=A[max];
                    A[max]=A[end];
                    A[end]=temp;
                 
                    temp=A[min];
                    A[min]=A[start];
                    A[start]=temp;
                }
                 
                if(min==end){
                    int temp=A[min];
                    A[min]=A[start];
                    A[start]=temp;
                     
                    temp=A[max];
                    A[max]=A[end];
                    A[end]=temp;
                }
            }
         
        }
 
        return A;
    }
};