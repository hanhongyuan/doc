#include <iostream>
using namespace std;

class MergeSort {
public:
    int* mergeSort(int* A, int n) {
        mergePass(A,0,n-1);
		return A;
    }

	void mergePass(int *A,int low,int high){
	
		if(low<high){
		
			if(high-low<=10){//Ԫ�ظ���С��һ������ʱ���ò������� �����Լ�ָ��
				InsertionSort(A,low,high);
				return ;
			}
			
			int middle=(low+high)/2;

			mergePass(A,low,middle);
			mergePass(A,middle+1,high);
            
			if(A[middle]<=A[middle+1]){//������м�����ǰ���������Ѿ����� ������һ������ ����Ҫ�ٴν��е���
               return;
           	}
            
			merge_func(A,low,high,middle);
		}
	}


	void merge_func(int *A,int low,int high,int mid){
	
		int *temp=new int [high-low+1];//����һ����ʱ�ռ�������õ�Ԫ��
		int k=0;
		int i=low;
		int j=mid+1;

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

		for(i=low,k=0;i<=high;i++,k++){//����ú����·Ż�ԭ������ȥ
			A[i]=temp[k];
		}
	}

	void InsertionSort(int *A,int start,int end){
		
		int temp=0;
		int j=0;
		for(int i=start+1;i<=end;i++){
			temp=A[i];
			j=i;
			while(j>start&&temp<A[j-1]){
				A[j]=A[j-1];
				j--;
			}
			A[j]=temp;
		}
	}
};