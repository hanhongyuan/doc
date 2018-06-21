class ShellSort {
public:
    int* shellSort(int* A, int n) {
        int gap=n/2;//���Ϊgap ÿ��gap����2
		int temp=0;
		int j=0;
		while(gap>=1){//�ο��������� ֻ������gap����1 ��gap����1�ͺͲ������������
		
			for(int i=gap;i<n;i++){
				temp=A[i];
				j=i;
				while(j>=gap&&temp<A[j-gap]){
					A[j]=A[j-gap];
					j-=gap;
				}
				A[j]=temp;
			}
			gap=gap/2;
		}
		return A;
    }
};