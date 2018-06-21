#include <iostream>
#include <vector>
using namespace std;

class Championship {
public:
    vector<int> calc(int k) {
        int fenmu=jishujiecheng(2*k);
		int fenzi=C(k+1,k-1)*jiecheng(k-1,k-1);
		int yue=gcd(fenmu,fenzi);
		fenmu=fenmu/yue;
		fenzi=fenzi/yue;
		vector<int> res;
		res.push_back(fenmu-fenzi);
		res.push_back(fenmu);
		return res;
    }
	// ����n��time�ν׳�
	int jiecheng(int n,int time)
    {
        int res=1;
         
        for(int i=n;time>0;i--)
        {
            res*=i;
            time--;
        }
 
        return res;
    }
    // Cmn��������� Cmn=m!/n!(m-n)!
    int C(int m,int n)
    {
        return jiecheng(m,n)/jiecheng(n,n);
    }
    // n�������׳� 1*3*5...2n-1
	int jishujiecheng(int n){
		int res=1;
		for(int i=1;i<n;i+=2){
			res*=i;
		}
		return res;
	}
	// շת����������Լ�� Ҫ��m>n
	int gcd(int m,int n){
		while(true){
			if((m=m%n)==0){
				return n;
			}
			if((n=n%m)==0){
				return m;
			}
		}
	}
};