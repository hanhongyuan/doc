import java.util.*;
 
public class ThreeColor {
    public int[] sortThreeColor(int[] A, int n) {
        int font=0;//����0������
        int back=n-1;//����2������
        int temp;
        int i=0;
        while(i<=back){
            if(A[i]==0){//�����0����������Ӧ����λ���ϣ�i����
                temp=A[i];
                A[i]=A[font];
                A[font]=temp;
                font++;
                i++;
                continue;
            }
            if(A[i]==2){//�����2,��������Ӧ������λ���ϣ�i���䣬��Ϊ��֪�����������������Ƿ���0�����ǻ���Ҫ�ƶ�
                temp=A[i];
                A[i]=A[back];
                A[back]=temp;
                back--;
            }
            if(A[i]==1){//�����1��������
              i++; 
            }
            
        }
        return A;
    }
}