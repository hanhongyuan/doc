import java.util.*;
 
public class Rotation {
    public boolean chkRotation(String A, int lena, String B, int lenb) {
        if(A==null||B==null||lena<0||lenb<0){
            return false;
        }
        A=A+A;
        return kmpSearch(A,B)==-1?false:true;
    }
    //����next����
    public int [] getnext(String str){
        int len=str.length();
        int j=0;
        int k=-1;
        int []next=new int [len];
        next[0]=-1;
        while(j<len-1){
            if(k==-1||str.charAt(j)==str.charAt(k)){
                k++;
                j++;
                if(str.charAt(k)!=str.charAt(j)){
                    next[j]=k;
                }else{
                    next[j]=next[k];
                }
            }else{
                k=next[k];
            }
        }
        return next;
    }
    //KMP�㷨 ����A�ַ������Ƿ����B�ַ��� �����ڷ��ص�һ���ַ�������λ�ã��������򷵻�-1  ��������뿴http://www.jianshu.com/p/826480d851ee
    public int kmpSearch(String str1,String str2){
        int len1=str1.length();
        int len2=str2.length();
        int [] next=getnext(str2);
        int j=0,i=0;
        while(j<len1&&i<len2){
            if(i==-1||str1.charAt(j)==str2.charAt(i)){
                i++;
                j++;
            }else{
                i=next[i];
            }
        }
        return i==len2?j-i:-1;
    }
}