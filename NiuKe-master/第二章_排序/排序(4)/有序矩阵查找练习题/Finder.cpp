class Finder {
public:
    bool findX(vector<vector<int> > mat, int n, int m, int x) {
        bool result=false;
		int col=m-1;//������
		int row=0;//������

		while(col>=0&&row<n){

			if(x==mat[row][col]){//����ȣ����ҵ������
				result=true;
				break;
			}

			if(x>mat[row][col]){//������ȵ�ǰ���������������һ��
				row++;
			}else{//������ǰһ��
				col--;
			}
		}

		return result;
    }
};