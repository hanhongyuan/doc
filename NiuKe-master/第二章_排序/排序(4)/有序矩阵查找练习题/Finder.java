import java.util.*;
 
public class Finder {
   public boolean findX(int[][] mat, int n, int m, int x) {
        int num=mat[0][m-1];
        int i=0;//������
	int j=m-1;//������
        while (i<n&&j>=0){
            num=mat[i][j];
            if (x>num){//������ȵ�ǰ���������������һ��
                i++;
            }
            if (x<num){//������ǰһ��
                j--;
            }
            if (x==num){//����ȣ����ҵ������
                return true;
            }
        }
        return false;
    }
}