class StackReverse {
public:
 
    stack<int> s1;
 
    vector<int> reverseStack(vector<int> A, int n) {// ��Ϊ����ʹ���������ջ�����Ա��������ջ��ʱ����Ҫ��ĩβѹջ
        int i;
 
        for(i=n-1;i>=0;i--)
        {
            s1.push(A.at(i));
        }
         
        rev(s1);// ����
        vector<int> res;
        while(!s1.empty())// ��Ԫ�ط��ظ�����
        {
            res.push_back(s1.top());
            s1.pop();
        }
 
        return res;
    }
     
    void rev(stack<int> &s)// ������
    {
        if(s.empty())
        {
            return ;
        }
         
        int val=getBottomValue(s);// ÿ�εݹ��ȡ��ǰջ�е�ջ��Ԫ�أ�Ȼ�����ʱ����ѹ��ջ�о���ɵ���Ĳ����ˡ�
        rev(s);
        s.push(val);
         
    }
 
    int getBottomValue(stack<int> &s)// �ݹ麯��������ɾ��ջ��Ԫ�ز�����ջ��Ԫ��
    {
        int res=s.top();
        s.pop();
        if(s.empty())
        {
            return res;
        }
        else
        {
            int val=getBottomValue(s);
            s.push(res);
            return val;
        }
    }
 
};