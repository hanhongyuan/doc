class Translation {
public:
    string stringTranslation(string A, int n, int len) {
        reverse(A.begin()+0,A.begin()+len);//�ȷ�ת0-len�����ַ���
		reverse(A.begin()+len,A.end());//�ٷ�תlen��ĩβ�ַ���
		reverse(A.begin(),A.end());//���ת�����ַ���
		return A;
    }
};