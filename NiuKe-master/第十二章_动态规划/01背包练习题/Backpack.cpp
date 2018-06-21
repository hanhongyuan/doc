#include <iostream>
#include <vector>
using namespace std;
 
 
class Backpack {
public:
 
     
    int max(int a,int b)
    {
        return a>b?a:b;
    }
 
    int maxValue(vector<int> w, vector<int> v, int n, int cap) {
         
        int **dp=new int *[n+1];
        int i,j;
        for(i=0;i<n;i++)
        {
            dp[i]=new int [cap+1];
        }
        
	//dp[i][j]=k ��ʾ��������j��ʹ��0..i����Ʒ��ɵ�����ܼ�ֵΪk 
        for(i=0;i<=cap;i++)//��ʼ����һ�У���������������w[0]ʱ�����Է���
        {
            if(i>=w[0])
            {
                dp[0][i]=v[0];
            }
            else
            {
                dp[0][i]=0;
            }
        }
 
        for(i=1;i<n;i++)
        {
            for(j=0;j<=cap;j++)
            {
                if(j-w[i]>=0)//�Ƚ�ʹ�õ�i����Ʒ�Ͳ�ʹ�õ�i����Ʒ���ܼ�ֵ��ȡ����Ǹ���ǰ���ǵ�ǰ���������ܷ����i����Ʒ������
                {
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
                }
                else//��ǰ�������ز��ܷ����i����Ʒ������ֻ��Ĭ�ϲ�ʹ�õ�i����Ʒ
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
         
        return dp[n-1][cap];
    }
};