class Prior {
public:
    string findSmallest(vector<string> strs, int n) {
       int i=n-1;
	   int pos=0;
	   while(i>0){//����������ð��������ص㣬�������е�ÿ��Ԫ�ؽ����˱Ƚϡ�
		  pos=0;
		  for(int j=0;j<i;j++){
			string str1=strs[j]+strs[j+1];
			string str2=strs[j+1]+strs[j];

			if(str1>str2){
				swap(strs,j,j+1);
				pos=j;
			}
		  }
		  i=pos;
	   }

	   string res;
	   for(i=0;i<n;i++){
		res+=strs[i];
	   }

	   return res;
    }

	void swap(vector<string> &strs,int i,int j)
    {
        string temp=strs[i];
        strs[i]=strs[j];
        strs[j]=temp;
    }
};