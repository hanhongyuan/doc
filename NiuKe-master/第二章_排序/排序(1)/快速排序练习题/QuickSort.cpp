class QuickSort {
public:
    int* quickSort(int* A, int n) {
        quickPass(A,0,n-1,n);
        return A;
    }

	void quickPass(int *A,int low,int high,int n){
	
		if(low==high){
			return ;
		}

		if(high-low<=10){//Ԫ�ظ���С��һ����ʱ��ʹ��Ч�ʸ��ߵĲ�������
			InsertionSort(A,low,high);
			return ;
		}

		int j=Partition(A,low,high,n);
        
		//�ݹ����
		if(j>low){
			quickPass(A,low,j-1,n);
		}

		if(j<high){
			quickPass(A,j+1,high,n);
		}
	}


	int Partition(int *A,int low,int high,int n){
		if(A==NULL||low<0||high>n){//��ȫ�߽���
			return -1;
		}

		int mid_index=(low+high)/2;//�������ʹ���м�ֵ��Ϊ��׼ֵ
		swap(A,mid_index,high);

		int j=low;
		for(int i=low;i<=high;i++){//�ѱȱ�׼ֵС���Ƶ�ǰ�棬����Ƶ����ĺ���
			if(A[i]<A[high]){
				swap(A,i,j);
				j++;
			}
		}
		swap(A,j,high);
		return j;//���ر�׼ֵ��ʱ�±�����
	}

	void swap(int *A,int a,int b){
		int temp=A[a];
		A[a]=A[b];
		A[b]=temp;
	}

	void InsertionSort(int *A,int start,int end){
		int j=0;
		int temp=0;
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