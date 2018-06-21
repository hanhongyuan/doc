class Gap {
public:
    int maxGap(vector<int> A, int n) {
        int max=A[0];
		int min=A[0];
		
		int i;
		for(i=0;i<n;i++){
			if(max<A[i]){
				max=A[i];
			}
			if(min>A[i]){
				min=A[i];
			}
		}

		if(max==min){
			return 0;
		}

		//��Ϊ���������в����Ķ���һ��Ͱ�е����ֵ����Сֵ�����Զ���������Ԫ�����ǾͲ���Ҫ��¼
		vector<int> maxs(n,INT_MIN);//��i��Ͱ�е����ֵ
		vector<int> mins(n,INT_MAX);//��i��Ͱ�е���Сֵ
		
		
		int len=max-min;

		for(i=0;i<n;i++){
			int bid=(double)(A[i]-min)/len*(n-1);//��λԪ�ؾ����ڼ���Ͱ��
			maxs[bid]=_max(maxs[bid],A[i]);//�������ֵ
			mins[bid]=_min(mins[bid],A[i]);//������Сֵ
		}
		
		int res=0;
		int pre=maxs[0];

		for(i=1;i<n;i++){
			if(mins[i]!=INT_MAX){//�������Ͱ����Ԫ��
				res=_max(res,mins[i]-pre);//��һ��Ͱ��Сֵ-ǰһ��Ͱ���ֵ
				pre=maxs[i];//�������ֵΪ��ǰͰ���ֵ��Ȼ��i+1��ô�ͱ��ǰһ��Ͱ��
			}
		}
		return res;
    }

	int _max(int a,int b){
		return a>b?a:b;
	}

	int _min(int a,int b){
		return a>b?b:a;
	}
};
