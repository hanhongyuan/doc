/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
 
class CountNodes {
public:
    int count(TreeNode* root) {
        TreeNode *temp=root;
 
        TreeNode *left=NULL;
        TreeNode *right=NULL;
        int l_node=0;
        int r_node=0;
 
        int res=1;
        while(temp->left!=NULL||temp->right!=NULL)
        {
            left=temp->left;
             
            l_node=0;
            r_node=0;
 
            while(left!=NULL)
            {
                l_node++;
                left=left->left;
            }
 
            right=temp->right;
 
            while(right!=NULL)
            {
                r_node++;
                right=right->left;
            }
 
            if(r_node==l_node)// �Ƚ�����ͷ�ڵ����� ��һ��˵����������һ���������� ֱ���ù�ʽ����ڵ�
            {
                res+=pow(2,l_node);
                temp=temp->right;
            }
            else// �Ƚ�����ͷ�ڵ����� ����һ��˵����������һ���������� ֱ���ù�ʽ����ڵ�
            {
                res+=pow(2,r_node);
                temp=temp->left;
            }
        }
 
        return res;
    }
};