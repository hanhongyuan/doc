class DistinctSubstring {
public:
    int longestSubstring(string A, int n) {
        map<char,int> m;//��ϣ��洢 �ַ�a�ϴγ��ֵ�λ��i
		int pre_index=-1;//�ַ�i��ǰһ���ַ�i-1���ϴγ��ֵ�λ��
		int temp=0;
		int res=0;//����ظ�����
		m[A[0]]=0;//��ʼ����һ���ַ��ϴγ��ֵ�λ�þ���0
		for(int i=1;i<n;i++){

			char ch=A[i];
			int cur;
			if(m.find(ch)!=m.end()){//�ڹ�ϣ����Ѱ���ϴγ��ֵ�λ�� �Ҳ�����Ϊ-1
				cur=m[ch];			
			}else{
				cur=-1;
			}
			/*
			�Ƚϵ�ǰ�ַ�i��i-1�ַ����ϴεĳ��ֵ�λ�ã�
			˭���ֵ�λ�ø�����i���������㳤��.��Ϊ���i-1�ַ��ϴγ��ֵ�λ�ñ�i��
			��ô˵��i�ַ�û���ϴ������ֵ�λ�þͻ���Ϊi-1�ַ��ظ���ʧ��(����i-1�ַ��ϴγ��ֵ�λ�þͲ����i�Ĵ�)
			��֮����˵��i�ַ����Ե��ϴγ��ֵ��ַ���λ�ã������м�i-1�ַ���֤���ᷢ���ظ�
			*/
			if(pre_index>cur){
				temp=i-pre_index;
			}else{
				temp=i-cur;
				pre_index=cur;//�����µ�λ�ü��㣬���Ը���pre_index
			}

			m[ch]=i;//�����ַ�ch�ϴγ��ֵ�λ��
			res=max(res,temp);
		}

		return res;
    }

	int max(int a,int b){
		return a>b?a:b;
	}
};
