//������� ��Ϊa^a=0 a^0=a ���Գ���ż���ε������ն�����0�� ֻʣ�������ε�����0��� ����Ȼ�����Ǹ������� ������������Ϻͽ�����
class OddAppearance {
public:
    int findOdd(vector<int> A, int n) {
         int e=0;
 
        for(int i=0;i<n;i++)
        {
            e=e^A[i];
        }
 
        return e;
    }
};