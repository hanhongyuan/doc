class TwoStack {
public:
 
    stack<int> s1;
    stack<int> s2;
 
    vector<int> twoStack(vector<int> ope, int n) {
        int i;
        vector<int> res;
        for(i=0;i<n;i++)
        {
            if(ope[i]>0)
            {
                push(ope[i]);
            }
 
            if(ope[i]==0)
            {
                res.push_back(pop());
            }
        }
 
        return res;
    }
 
    void push(int value)
    {
        s1.push(value);
    }
 
    int pop()
    {
        if(s2.empty())// �������ջΪ�գ���������������ʱ����Ҫ��ѹ��ջ�е�����ȫ��ת������ջ��ȥ
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }      
        }
        int t= s2.top();// Ȼ���ٵ�������ջ�е����ݣ�����ջ��������
        s2.pop();
        return t;
    }
};