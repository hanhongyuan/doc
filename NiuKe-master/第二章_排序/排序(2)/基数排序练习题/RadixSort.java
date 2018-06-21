import java.util.*;
 
public class RadixSort {
    public int[] radixSort(int[] A, int n) {
        radix_sort(A,n,findMaxNumber_digits(A));
        return A;
    }
    /**
     * �ҵ�����������������ж���λ
     * ���磺����������Ϊ123���򷵻�3
     * @param A ����
     * @return λ��
     */
    public int findMaxNumber_digits(int [] A){
        int max=A[0];
        for(int i=0;i<A.length;i++){
            max=Math.max(A[i],max);
        }
        return String.valueOf(max).length();
    }
 
    /**
     * ��ȡ���ֵĵ�nλ��
     * @param num ����ȡ������
     * @param n �ڼ�λ��
     * @return λ��
     */
    public int getNumberBydigit(int num,int n){
        int result=0;
        while (n>0){
            result=num%10;
            num=num/10;
            n--;
        }
        return result;
    }
    public int [] radix_sort(int [] A,int n,int radix){
        int [][] temp=new int[10][A.length];
        int [] count=new int[10];
        for (int i=1;i<=radix;i++){
            for (int j=0;j<A.length;j++){
                int numberBydigit = getNumberBydigit(A[j], i);
                temp[numberBydigit][count[numberBydigit]++]=A[j];
            }
            int k=0,m=0;
            for (int j=0;j<count.length;j++){
                while (count[j]!=0){
                    A[k++]=temp[j][m];
                    count[j]--;
                    m++;
                }
                m=0;
            }
        }
        return A;
    }
}