class Checker {
public:
    bool checkDuplicate(vector<int> a, int n) {
       a=headSort(a,n);
	   int i;
	   for(i=0;i<a.size()-1;i++){//�ź�������������ڵ��������������ظ���ֵ����
		   if(a[i]==a[i+1]){
			  return true;
		   }
	   }

	   return false;
    }
	
	//������
	vector<int> headSort(vector<int> a,int n){
		int i;

		for(i=n/2;i>=0;i--){
			head_and_just(a,i,n-1);
		}

		for(i=n-1;i>=0;i--){
			swap(a,0,i);
			head_and_just(a,0,i);
		}

		return a;
	}


	void head_and_just(vector<int> &A,int parent,int length){
		int temp=A[parent];
		int child=parent*2+1;

		while(child<length){
			if(child+1<length&&A[child+1]>A[child]){
				child++;
			}

			if(temp>A[child]){
				break;
			}

			A[parent]=A[child];
			parent=child;
			child=child*2+1;
		}

		A[parent]=temp;
	}

	void swap(vector<int> &A,int a,int b){
		int t=A[a];
		A[a]=A[b];
		A[b]=t;
	}
};