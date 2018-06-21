const int MOD=1000000007;
  
class QuickPower {
public:
    int getPower(int k, int N) {
              
        long res=1;
        long temp=k;
        for(;N>0;N>>=1)// ����һλ
        {
            if(N&1==1)// λ���� ��������0 ˵����ʱi�Ķ�����ĩβΪ1 Ҫ���м���
            {
                res*=temp;
            }
            temp=(temp*temp)%MOD;
            res%=MOD;
        }
  
        return res;
    }
};