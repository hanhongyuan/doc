import java.util.*;
 
public class ScaleSort {
    public int[] sortElement(int[] A, int n, int k) {
        int [] temp=Arrays.copyOf(A,k);//������СΪk������
        for (int i=k/2;i>=0;i--){//������ʼ��
            HeadAdjust(temp,i,k);
        }
        for (int i=k;i<n;i++){//��ʼ�ѵĶѶ�Ϊ�����������Сֵ����Ϊÿ��Ԫ���ƶ����벻����k�������������0-k��һ��������Сֵ
            A[i-k]=temp[0];//�ѶѶ���ֵ������ĵ�һ��λ��
            temp[0]=A[i];//������ĺ�һ��Ԫ�ؼ�����У������ڶѶ�
            HeadAdjust(temp,0,k);//������
        }
 
        for (int i=n-k;i<n;i++){//ʣ�µ�������k��С�Ķ���Ԫ�ذ���ԭʼ�Ķ�����������,Ҳ���ǰ�n-k��n�����Χ�����鰴�ն�����
            A[i]=temp[0];//�Ѷ�Ԫ�ظ�ֵ������
            //������һ��λ�ú����һ��λ��Ԫ��
            int t=temp[0];
            temp[0]=temp[k-1];
            temp[k-1]=t;
            HeadAdjust(temp,0,--k);//������
        }
        return A;
    }
    public void HeadAdjust(int [] A,int parent,int length){
        int temp=A[parent];
        int child=parent*2+1;//����
        while (child<length){
            if (child+1<length&&A[child]>A[child+1]){//�����Ƿ�����Һ��ӣ�������ڲ����Һ��ӻ�С ��ѡȡ�Һ���
                child++;
            }
            if (temp<=A[child]){//���ӽڵ�ͺ��ӽڵ�����С�Ľڵ���бȽ� ������ӽڵ㻹С ����ô�ͷ��ϸ��ӽڵ���������ӽڵ�Ĺ��� ��ֱ��break��
                break;
            }
            A[parent]=A[child];//���ӽڵ����С���ӽڵ㽻��
            parent=child;//����ɸѡ
            child=child*2+1;
        }
        A[parent]=temp;//���һ���ڵ������ڵ㽻��
    }
}