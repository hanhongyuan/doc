/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
 
class TreePrinter {
public:
    vector<vector<int> > printTree(TreeNode* root) {
        vector< vector<int> > v;
        vector<int> v1;
         
        queue<TreeNode *> q;// ����һ������ ʹ��ջ�Ͳ�����
 
        q.push(root);
 
        TreeNode *last=NULL;
        TreeNode *nlast=NULL;
        last=root;
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            v1.push_back(temp->val);
 
            if(temp->left!=NULL)// �ѵ�ǰ�ڵ���ڵ��������� ע��������Ƚ��ȳ������ݽṹ �����ӡ��Ҫ���Ǵ����� ����Ҫע�����ҽڵ������е�˳
            {
                q.push(temp->left);
                nlast=temp->left;
            }
 
            if(temp->right!=NULL)// �ѵ�ǰ�ڵ��ҽڵ���������
            {
                q.push(temp->right);
                nlast=temp->right;
            }
 
            if(temp==last)// ����һ�е�ĩβ
            {
                v.push_back(v1);
                v1.clear();
                last=nlast;// ����last
            }
        }
 
        return v;
    }
};