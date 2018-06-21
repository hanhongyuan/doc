#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
 * �����������������N���ε�N�����ϣ�ÿ�����Ͽ�����2���߷�ѡ������һ����2��n�η����߷�
 * Ȼ����ͷ�ĵ����ֻ��2�� ���Ǵ�Ҷ�˳ʱ���ߺ���ʱ���� ������ͷ�ĸ��ʾ��� �ܵ��߷�-2/�ܵ��߷�
 */
class Ants {
public:
    vector<int> collision(int n) {
        int fenmu=pow(2,n);
		int fenzi=fenmu-2;
		int yue=gcd(fenmu,fenzi);
		fenmu=fenmu/yue;
		fenzi=fenzi/yue;
		vector<int> res;
		res.push_back(fenzi);
		res.push_back(fenmu);

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


