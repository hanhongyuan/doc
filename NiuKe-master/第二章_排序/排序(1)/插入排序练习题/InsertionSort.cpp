class InsertionSort {
public:
    int* insertionSort(int* A, int n) {
        int temp=0;
        int j=0;
        for(int i=1;i<n;i++){
            j=i;
            temp=A[j];//��¼��ǰ�ڵ�ֵ
            while(j>0&&temp<A[j-1]){//�ӵ�ǰ�ڵ㿪ʼ����ǰ����һ�β���������̲���ֵԪ��
                A[j]=A[j-1];
                j--;
            }
            A[j]=temp;//���ѽڵ�ֵ�Żؽ���������
        }
         
        return A;
    }
};