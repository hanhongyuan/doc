#include <iostream>
#include <vector>
using namespace std;
 
const int max_n=50;
const int max_aim=1000;
 
//dp[i][j] ʹ��0..i�ֻ������Ǯ��J�ķ�����
int dp[max_n+1][max_aim+1];
 
 
class Exchange {
public:
    int countWays(vector<int> penny, int n, int aim) {
         
        int i;
     
        for(i=0;i<n;i++){//��ʼ����һ�� ʹ��0...i���������Ǯ��0�ķ�����Ϊ1 ���Ƕ���ʹ��
            dp[i][0]=1;
        }
 
        for(i=0;i<=aim;i++){//��ʼ����һ�� ʹ�õ�0���������Ǯ��i�ķ��������Ǿ���˵ֻ�е�Ǯ���պ��ܹ�������0�����ҵ���ֵʱ��һ�ַ���
            if(i%penny[0]==0){
                dp[0][i]=1;
            }else{
                dp[0][i]=0;
            }
        }
 
        for(i=1;i<n;i++){
         
            for(int j=0;j<=aim;j++){
                if(j>=penny[i]){//��Ǯ�����ڵ�i�����ҵ���ֵʱ���п���ʹ�õ�i������
                    dp[i][j]=dp[i-1][j]+dp[i][j-penny[i]];
                    /*�����ʽ���������ģ�
                    dp[i][j]����Դ:
                      1.ʹ��m��(m=0,1,2...)i�������j�ķ�����(ʹ��0��dp[i-1][j-0*penny[i]],ʹ��1��dp[i-1][j-1*penny[i]],ʹ��2��dp[i-1][j-2*penny[i]].....)
                       
                      ����Ĺ�ʽ��ʵ���ǰ�m=0���������˳����������dp[i][j-penny[i]]��ʾm=1��ʼ�����
                      Ϊʲôdp[i][j-penny[i]]�ܱ�ʾm=1������أ� ��ʵ�㿴���ʽ�Ӵ��ص��������ʹ��m��i�������j-penny[i]�ķ�����
                    */
                }else{//Ǯ��С��penny[i]������ʹ��i���� ֻ��ʹ��i-1������ȥ���Ǯ��J
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
 
        return dp[n-1][aim];//�������ս��
    }
};