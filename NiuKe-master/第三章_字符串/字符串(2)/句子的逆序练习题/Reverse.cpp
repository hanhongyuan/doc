class Reverse {
public:
    string reverseSentence(string A, int n) {
        reverse(A.begin(),A.end());//�Ƚ��ַ������巴ת
        int i,j;//�����±��������ֱ�ָ��Ҫ��ת�ַ�����ǰ�ͺ�
        for(i=0;i<n;i++){
            j=i;
            while(j<n&&A[j]!=' '){//�������ո�ʱ����תÿһ������
                j++;
            }
            reverse(A.begin()+i,A.begin()+j);
            i=j;
        }
        return A;
    }
};