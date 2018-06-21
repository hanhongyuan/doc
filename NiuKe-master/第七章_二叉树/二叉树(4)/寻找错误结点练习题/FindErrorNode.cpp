/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
 
class FindErrorNode {
public:
    vector<int> findError(TreeNode* root) {
        vector<int> res;
        InOrderFindError(root,res);
        int i;
        int pos1=0;// λ��1
        int pos2=0;// λ��2
        int t=0;
        for(i=1;i<res.size();i++)
        {
            if(res[i]<res[i-1]&&t==0)// �����ֵ�һ�ν�����̵�ʱ��
            {
                pos1=i-1;// ȡ�ϴ���Ǹ�Ԫ��
                t++;
            }
            else if(res[i]<res[i-1]&&t==1)// ���ڶ��γ��ֽ�����̵�ʱ��
            {
                pos2=i;// ȡ��С���Ǹ�Ԫ��
                t++;
            }
        }
 
        vector<int> arr;// ֵ�Ĵ�С˳��������
        if(t==1)// ��1�ν������ ��Ӧ����ֻ��һ��λ��
        {
            arr.push_back(res[pos1+1]);
            arr.push_back(res[pos1]);
        }
        else if(t==2)// ��2�ν������ ��Ӧ��2��λ�ó���
        {
            arr.push_back(res[pos2]);
            arr.push_back(res[pos1]);
        }
 
        return arr;
    }
    // ����������Ԫ�ص�����
    void InOrderFindError(TreeNode * root,vector<int> &res)
    {
        if(root==NULL)
        {
            return ;
        }
 
        InOrderFindError(root->left,res);
        res.push_back(root->val);
        InOrderFindError(root->right,res);
    }
};