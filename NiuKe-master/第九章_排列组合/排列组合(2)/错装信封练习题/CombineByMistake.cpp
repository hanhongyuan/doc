#include <iostream>
using namespace std;

/*
 * ����һ����̬�滮���⣺
 * ����n���Ų�װ�ػ����ŷ��װ����f(n)��
 * ��ô�����n����װ���i���ŷ⣺�������������
 * 1.��i����װ��n���ŷ�(�൱�����߻���) ����n-2����f(n-2)��װ��
 * 2.��i���Ų�װ��n���ŷ�(���߲�����) ����n-1����Ҫװ f(n-1)
 * Ȼ��ÿһ���Ŷ���������һ����� ��ôf(n)=(n-1)*(f(n-1)+f(n-2))
 */
class CombineByMistake {
public:
    int countWays(int n) {
		if(n<=1){
			return 0;
		}else if (n==2){
			return 1;
		}else{
			long *dp=new long [300+1];
			dp[0]=0;
			dp[1]=0;
			dp[2]=1;

			for(int i=3;i<=n;i++){
				dp[i]=(i-1)*(dp[i-2]+dp[i-1])%1000000007;
			}

			return (int)dp[n];
		}
    }
};