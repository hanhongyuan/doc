#include <iostream>
using namespace std;


const int N=300;

//dp[i][j]=k �����ַ���A[0..i-1]����ַ���B[0...j-1]��Ҫ����С����Ϊk
int dp[N+1][N+1];


class MinCost {
public:
    int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
		int i,j;
		
		for(i=0;i<=n;i++){//��ʼ����һ�У��ַ���A[0..i-1]��ɿմ��Ĵ��۾���ɾ��i���ַ�
			dp[i][0]=i*c1;
		}

		for(i=0;i<=m;i++){//��ʼ����һ�У��մ�A����ַ���B[0...i-1]�Ĵ��۾��ǲ���i���ַ�
			dp[0][i]=i*c0;
		}

		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(A.at(i-1)==B.at(j-1)){//��iλ�ú�jλ���ַ����ʱ����3������ֵ
					int val_1=dp[i-1][j-1];//�͵���i-1���j-1�Ĵ���
					int val_2=dp[i-1][j]+c1;//����i-1���j����Ȼ��ɾ��һ��i�ַ�
					int val_3=dp[i][j-1]+c0;//����i���j-1��������һ��j�ַ�

					dp[i][j]=min(val_1,val_2);
					dp[i][j]=min(dp[i][j],val_3);
				}else{//��iλ�ú�jλ���ַ������ʱ����3������ֵ
					int val_1=dp[i-1][j]+c1;//����i-1���j����Ȼ��ɾ��һ��i�ַ�
					int val_2=dp[i][j-1]+c0;//����i���j-1��������һ��j�ַ�
					int val_3=dp[i-1][j-1]+c2;//����i-1���j-1����Ȼ���滻i�ַ����j�ַ�
					
				    dp[i][j]=min(val_1,val_2);
					dp[i][j]=min(dp[i][j],val_3);
				}
			}
		}

		return dp[n][m];
    }

	int min(int a,int b){
		return a>b?b:a;
	}
};