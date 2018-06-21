import java.util.*;
 
public class Prior {
    public String findSmallest(String[] strs, int n) {
        if (strs==null||n==0){
            return "";
        }
        Arrays.sort(strs,new Mycomparator());//����
        StringBuilder builder=new StringBuilder();//�ַ������������ַ���ƴ��
        for (int i=0;i<n;i++){
            builder.append(strs[i]);
        }
        return builder.toString();
    }
 
    private class Mycomparator implements Comparator<String>{//���ñȽ��������Զ���Ƚ�
 
        @Override
        public int compare(String o1, String o2) {
            return (o1+o2).compareTo(o2+o1);
        }
    }
}