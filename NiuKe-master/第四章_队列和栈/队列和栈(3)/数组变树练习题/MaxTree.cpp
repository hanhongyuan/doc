#include <iostream>
#include <vector>
using namespace std;

class MaxTree {
public:
    vector<int> buildMaxTree(vector<int> A, int n) {
        
		vector<int> res;
		for(int i=0;i<n;i++){//����ÿ��ֵȥ��ȡ���
			res.push_back(getIndex(i,A,n));
		}

		return res;
    }
	
	int getIndex(int target,vector<int>A,int n){
		int right=n;//�ұߵ�һ���������������
		int left=-1;//��ߵ�һ���������������
		int i;
		for(i=target+1;i<n;i++){//����������
			if(A[i]>A[target]){
				right=i;
				break;
			}
		}

		for(i=target-1;i>=0;i--){//����������
			if(A[i]>A[target]){
				left=i;
				break;
			}
		}

		if(left==-1&&right==n){//������������û�仯��˵���������߶�û�б�������������ڵ㷵��-1
			return -1;
		}else if(left!=-1&&right!=n){//���������������仯�ˣ���ʱ����Ԫ�ظ�С���Ǹ�����
			return A[left]>A[right]?right:left;
		}else if(left==-1&&right!=n){//�������б仯��������û�С�˵���ұ߸�С������
			return right;
		}else if(left!=-1&&right==n){//ͬ�� �������
			return left;
		}

		return 0;//Ϊ��ţ����OJ��Ҫһ������ֵ
	}
};
