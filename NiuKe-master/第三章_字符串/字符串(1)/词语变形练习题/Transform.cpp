
class Transform {
public:
    bool chkTransform(string A, int lena, string B, int lenb) {
        
        int letter[256];//��ʼ�����飬ȫ��Ϊ0 �������������ַ����ֵĴ���
        memset(letter,0,sizeof(letter));
        
        if(lena!=lenb){//���Ȳ���� ��ֱ�ӷ���false
			return false;
		}

		
		int i;
		for(i=0;i<lena;i++){//�ַ���A���ֵ��ַ�������Ӧ��ascii��λ���ϼ�1
			letter[A.at(i)]++;
		}

		for(i=0;i<lenb;i++){//�ַ���B���ֵ��ַ�������Ӧ��λ�ü�1�������ն���0����true ��һ�����Ǿ�Ϊfalse
			if(letter[B.at(i)]--==0){
				return false;
			}
		}

		return true;
    }
};