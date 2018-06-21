class Swap {
public:
    vector<int> getSwap(vector<int> num) {
        swap(num[0],num[1]);
        return num;
    }
    /*
	 ����˵����
	 a=a^b
	 b=a^b  ʽ�ӱ仯��: b=a^b^b ��Ϊ b^b=0 ���� b=a^0=a;
	 a=a^b  ʽ�ӱ仯��: a=a^b^a ����a=b
    */
    void swap(int &a,int &b)
    {
        a=a^b;
        b=a^b;
        a=a^b;
    }
};