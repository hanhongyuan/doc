#include <iostream>
using namespace std;


const int N=300;

//dp[i][j]=k �����ַ���A[0...i-1]���ַ���B[0...j-1]������������г���Ϊk
int dp[N+1][N+1];


class LCS {
public:
    int findLCS(string A, int n, string B, int m) {
        int i,j;
		int flag=0;
		for(i=0;i<n;i++){//��ʼ����һ�У��ַ���A[0...n-1]���ַ���B��0���ַ�������������г���
			if(flag==1||A.at(i)==B.at(0)){//���ڶ�Ӧλ���ַ���Ⱥ���һֱΪ1
				dp[i][0]=1;
				flag=1;
			}else{//����Ϊ0
				dp[i][0]=0;
			}
		}

		flag=0;

		for(j=0;j<m;j++){//��ʼ����һ�У�ԭ��ͬ�ϡ��ַ���������һ��
			if(flag==1||A.at(0)==B.at(j)){
				dp[0][j]=1;
				flag=1;
			}else{
				dp[0][j]=0;
			}
		}

		for(i=1;i<n;i++){
			for(j=1;j<m;j++){
				if(A.at(i)==B.at(j)){//iλ���ַ���jλ���ַ���ȣ���3������ֵ
					int val_1=dp[i-1][j-1]+1;//����i-1��j-1�ĳ���+1
					int val_2=dp[i-1][j];//����i-1��j�ĳ��ȣ���Ϊ������i-1�����Ѿ���j����������ˣ�
					int val_3=dp[i][j-1];//����i��j-1�ĳ��ȣ�������j-1�����к�i��Ĺ�����

					dp[i][j]=max(val_1,val_2);
					dp[i][j]=max(dp[i][j],val_3);
				}else{//iλ���ַ���jλ���ַ�����ȣ���2������ֵ�������˵�һ�����
					int val_1=dp[i-1][j];
					int val_2=dp[i][j-1];
					dp[i][j]=max(val_1,val_2);
				}
			}
		}

		return dp[n-1][m-1];
    }

	int max(int a,int b){
		return a>b?a:b;
	}
};