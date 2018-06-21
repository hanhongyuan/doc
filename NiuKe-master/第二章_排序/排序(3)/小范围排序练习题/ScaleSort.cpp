class ScaleSort {
public:
    vector<int> sortElement(vector<int> A, int n, int k) {
        
		int i;

		vector<int> minheap(k);//����һ��k��С��С����
		
		for(i=0;i<k;i++){//��������A��ǰK��ֵ��ʼ��С����
            minheap[i] = A[i];
        }

		for(i=k/2;i>=0;i--){//������ʼ��
			head_and_just(minheap,i,k);
		}

		for(i=0;i<n-k;i++){//������A��ֵ��С���ѶѶ��滻��Ȼ�����ѵ�����
			A[i]=minheap[0];
			minheap[0]=A[i+k];
			head_and_just(minheap,0,k);
		}

		for(i=n-k;i<n;i++){//ʣ�����k������ÿ�ε���С���ѣ��ѶѶ�Ԫ�ظ�ֵ��A����󣬾���СС���ѵĴ�С
			A[i]=minheap[0];
			minheap[0]=minheap[k-1];
			head_and_just(minheap,0,k--);
		}

		return A;
    }
	//����С���ѵĺ���
	void head_and_just(vector<int> &A,int start,int end){
		int temp=A[start];
		int child=start*2+1;

		while(child<end){
			if(child+1<end&&A[child+1]<A[child]){
				child++;
			}

			if(temp<A[child]){
				break;
			}

			A[start]=A[child];
			start=child;
			child=child*2+1;
		}

		A[start]=temp;
	}
};