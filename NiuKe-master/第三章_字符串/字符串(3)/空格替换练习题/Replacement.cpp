class Replacement {//��ָofferԭ�� �滻�ո�
public:
    string replaceSpace(string iniString, int length) {
        int numOfblank=0;
		int i;
		for(i=0;i<length;i++){//����ո������
			if(iniString[i]==' '){
				numOfblank++;
			}
		}

		int len=length+numOfblank*2;//���ַ�������
		char *str=new char [len];//�����µ��ַ�����
		str[len]='\0';
		int k=len-1;
		for(i=length-1;i>=0;i--){//����ֵ �����ո�ֵ%20
			if(iniString[i]==' '){
				str[k--]='0';
				str[k--]='2';
				str[k--]='%';
			}else{
				str[k--]=iniString[i];
			}
		}

		return str;
    }
};
