class ThreeColor {
public:
    vector<int> sortThreeColor(vector<int> A, int n) {
        int index_0=0;//����0������
		int index_2=n-1;//����2������
		int i=0;

		while(i<=index_2){
			if(A[i]==1){//�����1��������
				i++;
			}else if(A[i]==0){//�����0����������Ӧ����λ���ϣ�i����
				swap(A,index_0,i);
				index_0++;
				i++;
			}else if(A[i]==2){//�����2,��������Ӧ������λ���ϣ�i���䣬��Ϊ��֪�����������������Ƿ���0�����ǻ���Ҫ�ƶ�
				swap(A,index_2,i);
				index_2--;
			}
		}

		return A;
    }

	void swap(vector<int> &A,int a,int b){
		int t=A[a];
		A[a]=A[b];
		A[b]=t;
	}
};