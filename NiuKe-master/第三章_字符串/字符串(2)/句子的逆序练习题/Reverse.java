import java.util.*;
 
public class Reverse {
    public String reverseSentence(String A, int n) {
        StringBuilder bulider=new StringBuilder();
        String[] split = A.split(" ");//�з��ַ���
        for (int i=split.length-1;i>=0;i--){//���ַ�������ƴ��
            bulider.append(split[i]+" ");
        }
        return bulider.substring(0,bulider.length()-1).toString();
    }
}