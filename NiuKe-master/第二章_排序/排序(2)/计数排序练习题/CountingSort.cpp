#include <iostream>
using namespace std;


class CountingSort {
public:
    int* countingSort(int* A, int n) {
        int i;
		int max=A[0];
		int min=A[0];

		for(i=0;i<n;i++){//�ҵ����ֵ����Сֵ������ȷ�������С
			if(A[i]>max){
				max=A[i];
			}

			if(A[i]<min){
				min=A[i];
			}
		}
		int len=max-min+1;
		int *arr=new int [len];//����һ���µ����飬��СΪlen


		
		for(i=0;i<len;i++){
			arr[i]=0;
		}

		for(i=0;i<n;i++){//�����ָ�ֵ����������
			arr[A[i]-min]++;
		}

		int k=0;

		for(i=0;i<len;i++){//����˳�����ε�������
			while(arr[i]>0){
				A[k++]=i+min;
				arr[i]--;
			}
		}

		return A;
    }
};

