#include <iostream>
using namespace std;

const int N=100000;
const int MOD=1000000007;


//dp[i]=k ������i��̨�׵ķ�����Ϊk
int dp[N+1];

class GoUpstairs {
public:
    int countWays(int n) {
        dp[1]=1;//��һ��̨��ֻ��һ�ַ���
		dp[2]=2;//������̨�������֣�һ����һ������һ��������

		for(int i=3;i<=n;i++){
			dp[i]=(dp[i-1]+dp[i-2])%MOD;
			/*��ô��ʵ�ϵ�i��̨�׿�����������������õ�:
			  1.һ�־�������i-1��֮������һ��
			  2.һ�־�������i-2��֮�����϶���

			  ������Ӽ��ɵõ�
			*/
		}

		return dp[n];
    }
};