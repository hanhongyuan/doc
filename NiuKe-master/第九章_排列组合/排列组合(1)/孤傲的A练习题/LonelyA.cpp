class LonelyA {
public:
    int getWays(int n, int A, int b, int c) {//���������ȫ���� Ȼ���ȥA�ֱ�������һ���˵�ȫ���� ������ʱ���ظ����һ���ֹ��������У�����
        int total=jiecheng(n,n);
        int aa=jiecheng(n-1,n-1)*2;
        int bb=aa;
        int cc=jiecheng(n-2,n-2)*2;
         
        return total-aa-bb+cc;
    }
     
    int jiecheng(int n,int time)
    {
        int res=1;
         
        for(int i=n;time>0;i--)
        {
            res*=i;
            time--;
        }
 
        return res;
    }
     
    int C(int m,int n)
    {
        return jiecheng(m,n)/jiecheng(n,n);
    }
};