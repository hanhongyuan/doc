class StandInLine {
public:
    vector<int> getWays(int n, int a, int b) {
        vector<int> res(2,0);
        res[0]=jiecheng(n,n)/2;// ȫ����֮�� ��Ϊa��bֻ��������� Ҫ��a��b��� Ҫ��a��b�ұ� ����ȡһ�뼴��
        res[1]=jiecheng(n-1,n-1);// Ҫ������ �������һ����Ȼ�����n-1ȫ���м���
         
        return res;
    }
      // ����n��time�ν׳�
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
};