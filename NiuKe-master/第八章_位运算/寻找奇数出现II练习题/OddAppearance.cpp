class OddAppearance {
public:
    vector<int> findOdds(vector<int> arr, int n) {
        int e=0;
        int i;
        for(i=0;i<n;i++)//�����������0������� �õ��Ľ��Ϊ2�����������ε����������
        {
            e=e^arr[i];
        }
 
        int flag=0;
 
        for(i=0;i<32;i++)//Ѱ��2�����������ε����ڵڼ�λ�ϲ�ͬ ����Ϊ��iλ
        {
            flag=(1<<i);
            if((e&flag)!=0)
            {
                break;
            }
        }
 
        vector<int > res(2,0);
 
        for(i=0;i<n;i++)
        {
            if((arr[i]&flag)==flag)//˵����flag�ڵ�iλ����ͬ ����Щ��ͬ�����������  ��������һ�����������ε���
            {
                res[0]=res[0]^arr[i];
            }
            else//����������һ�������ε���
            {
                res[1]=res[1]^arr[i];
            }
        }
         
        sort(res.begin(),res.end());
 
        return res;
    }
};