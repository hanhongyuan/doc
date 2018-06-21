import java.util.*;
 
public class Transform {
    public boolean chkTransform(String A, int lena, String B, int lenb) {
        if (A==null||B==null||lena!=lenb){//���Ȳ���� ��ֱ�ӷ���false
            return false;
        }
        int [] map=new int[256];//��ʼ�����飬ȫ��Ϊ0 �������������ַ����ֵĴ���
        for (int i=0;i<A.length();i++){//�ַ���A���ֵ��ַ�������Ӧ��ascii��λ���ϼ�1
            map[A.charAt(i)]++;
        }
        for (int i=0;i<B.length();i++){//�ַ���B���ֵ��ַ�������Ӧ��λ�ü�1�������ն���0����true ��һ�����Ǿ�Ϊfalse
            if (map[B.charAt(i)]--==0){
                return false;
            }
        }
        return true;
    }
}