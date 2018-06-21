/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
 
class TreeToSequence {
public:
    vector<vector<int> > convert(TreeNode* root) {
       TreeNode * root1=root;
       vector<int> res1=PreOrder(root1);
 
       TreeNode * root2=root;
       vector<int> res2=InOrder(root2);
 
       TreeNode * root3=root;
       vector<int> res3=ReverseOrder1(root3);
        
        
       vector<vector<int> >res;
 
       res.push_back(res1);
       res.push_back(res2);
       res.push_back(res3);
 
       return res;
    }
    // �ǵݹ�ǰ�����������
    vector<int> PreOrder(TreeNode *root)
    {
        stack<TreeNode*>s;// ��һ��ջ�洢�ڵ�
 
        TreeNode * cur;
 
        s.push(root);
        vector<int> res;
        while(!s.empty())
        {
            cur=s.top();
            s.pop();
            res.push_back(cur->val);
 
            if(cur->right!=NULL)// �ȼ����ҽڵ� ��Ϊջ���Ƚ���������ݽṹ ����������������������˳��
            {
                s.push(cur->right);
            }
            if(cur->left!=NULL)
            {
                s.push(cur->left);
            }
        }
 
        return res;
    }
     // �ǵݹ��������������
    vector<int> InOrder(TreeNode * root)
    {
        stack<TreeNode *> s;
 
        TreeNode * cur=root;
        vector<int > res;
        while(!s.empty()||cur!=NULL)
        {
            while(cur!=NULL)
            {
                s.push(cur);
                cur=cur->left;
            }
 
            if(!s.empty())
            {
                TreeNode * temp=s.top();// ����ջ���ڵ�
                s.pop();
                res.push_back(temp->val);
                cur=temp->right;// ָ��ǰ�ڵ���ҽڵ�
            }
        }
 
        return res;
    }
     
    //����ջ
    vector<int> ReverseOrder(TreeNode *root)
    {
        stack<TreeNode * >s1;
        stack<TreeNode * >s2;
        TreeNode * cur;
        s1.push(root);
 
        vector<int >res;
        while(!s1.empty())
        {
            cur=s1.top();
            s1.pop();
            s2.push(cur);
 
            if(cur->left!=NULL)
            {
                s1.push(cur->left);
            }
            if(cur->right!=NULL)
            {
                s1.push(cur->right);
            }
        }
 
        while(!s2.empty())
        {
            cur=s2.top();
            s2.pop();
            res.push_back(cur->val);
        }
 
        return res;
    }
 
    //һ��ջ
    vector<int> ReverseOrder1(TreeNode * root)
    {  
        TreeNode *h;// �������һ�δ�ӡ����Ľڵ�
        TreeNode *c;
 
        stack<TreeNode *>s;
        vector<int> res;
        h=root;
        c=NULL;
 
        s.push(root);
 
        while(!s.empty())
        {
            c=s.top();
 
            if(h!=c->left&&c->left!=NULL&&h!=c->right)// ��ǰ�ڵ�c�����ҽڵ㶼������hͬʱ��������Ϊ�գ�˵�����ӻ�û�д�ӡ ����������ջ
            {
                s.push(c->left);
            }
            else if(h!=c->right&&c->right!=NULL)// ��ǰ�ڵ�c���ҽڵ㲻����hͬʱ�ҽڵ㲻Ϊ�գ�˵���ҽڵ㻹û�д�ӡ�� ���԰��ҽڵ����ջ��
            {
                s.push(c->right);
            }
            else
            {// �����������������Ļ� ˵��Ҫ��ӡ��ǰ�ڵ��� ͬʱ��h=c ��Ϊc�ո�������
                res.push_back(c->val);
                s.pop();
                h=c;
            }
        }
 
        return res;
    }
}; 