
class Subsequence {
public:
    int shortestSubsequence(vector<int> A, int n) {
        int big=A[0];
		int small=A[n-1];
		int p=0;
		int q=n-1;
		for(int i=0;i<n;i++){
			if(big>A[i]){//�����i������big�󣬸���big��ֱ��������bigС����¼�±ꡣ�±�����ͣ�������һ����bigС�����ϡ���ô�������̾����˴Ӵ�С�ٴ��м��δ���������ĩβ�����±�p
				p=i;
			}else{
				big=A[i];
			}

			if(small<A[n-i-1]){//�����n-i-1������smallС������small��ֱ��������small�󣬼�¼�±ꡣ�±�����ͣ�������һ����small������ϣ��������̾����˴�С������С���м��δ����Ŀ�ͷ�����±�q
				q=n-i-1;
			}else{
				small=A[n-i-1];
			}
		}

		if(p==0&&q==n-1){
			return 0;
		}

		return p-q+1;
    }
};