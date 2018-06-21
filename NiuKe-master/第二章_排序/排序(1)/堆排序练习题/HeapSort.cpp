#include <iostream>
using namespace std;

class HeapSort {
public:
    int* heapSort(int* A, int n) {
		for(int i=n/2;i>=0;i--){//������ʼ�� ��2/n��ʼ����������
			head_adjust(A,i,n-1);
		}

		for(int i=n-1;i>=0;i--){//�ѶѶ�Ԫ��Ҳ�������ֵ�ŵ����Ȼ��ÿ�ν���һ�ζѵ���
			swap(A,0,i);
			head_adjust(A,0,i);
		}

		return A;
    }

	void head_adjust(int *A,int parent,int length){
		int temp=A[parent];//��¼���ڵ�ֵ
		int child=parent*2+1;//ȡ���ӽڵ�����
		while(child<length){
			
			if(child+1<length&&A[child]<A[child+1]){//�����ǹ��������
				child++;//ȡ�������ӽڵ��������Ǹ�
			}

			if(temp>A[child]){//������ڵ���ں��ӽڵ� ���˳� �������ڵ���������
				break;
			}
			//ѭ�����ӽڵ����
			A[parent]=A[child];
			parent=child;
			child=child*2+1;
		}

		A[parent]=temp;//������ĸ��ڵ�Żض�������
	}

	void swap(int *A,int a,int b){
		int temp=A[a];
		A[a]=A[b];
		A[b]=temp;
	}
};
