
/*
	  ����������ۺ���⣺ a��b������ͬ�� diffabΪ0 sameabΪ1 ��ʱ��cs�ķ��� ��a����b csΪ1 ��ôreturnAΪ1
	  returnBΪ0 �����ȷ a��b���Ų���ͬ�� diffabΪ1 sameabΪ0 ��ʱ��as�ķ��� ��aΪ����bΪ�� �ǽ���϶�Ϊa����b
	  ��returnAΪ1 returnBΪ0 �����ȷ aΪ��bΪ�� �ǿ϶�b����a returnAΪ0 returnBΪ1 �����ȷ
*/
class Compare {
public:
    int getMax(int a, int b) {
        int sa=sign(a);//��ȡa�ķ���
        int sb=sign(b);//��ȡb�ķ���
        int sc=sign(a-b);//��ȡa-b�ķ���
        int difsab=sa^sb;// ab������ͬ��Ϊ0 ab���Ų�ͬ��Ϊ1
        int samesab=flip(difsab);//��difab�෴
 
        int returnA=sa*difsab+sc*samesab;
        int returnB=flip(returnA);
 
        return b*returnA+a*returnB;
    }
 
    int sign(int n)
    {
        return (n>>31)&1;
    }
 
    int flip(int n)
    {
        return n^1;
    }
 
};