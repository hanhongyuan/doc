#include <iostream>
using namespace std;

const int N=500;

//dp[i]=k����������i����λ�ý�β������������г���Ϊk 
int dp[N+1];

class LongestIncreasingSubsequence {
public:
    int getLIS(vector<int> A, int n) {
        dp[0]=1;//�����һ����������������о��Ǳ�������Ϊ1
		int temp;
		int max=0;
		for(int i=1;i<n;i++){
			temp=0;
			for(int j=i-1;j>=0;j--){//�ӵ�i������ǰѰ�ұȵ�i����С����Ϊ���������У�Ȼ��������������ҵ���֪��������Ǹ��������ټ��ϵ�i��������ʹ����������
				if(A[i]>A[j]&&dp[j]>temp){
					temp=dp[j];
				}
			}
			dp[i]=temp+1;
			if(dp[i]>max){
				max=dp[i];
			}
		}

		return max;
    }
};