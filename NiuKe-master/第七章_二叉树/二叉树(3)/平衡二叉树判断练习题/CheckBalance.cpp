/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class CheckBalance {
public:
    bool check(TreeNode* root) {
       return chk(root)>=0;
    }
    int chk(TreeNode * root){// ʹ�ú������
        if(root==NULL){
            return 0; 
        }
        int l=chk(root->left);// �������߶�
        int r=chk(root->right);// �������߶�
        
        if(l<0||r<0){// ��Ϊ-1 ��˵����������Ϊ��ƽ�������
            return -1;
        }
        
        if(abs(l-r)>1){// �������������Ƿ�ƽ������� ��ʱ�ж����������ĸ߶Ȳ� ����1 ���Ƿ�ƽ������� ����
            return -1;
        }
        
        return l>r?l+1:r+1;// ���������߶�
    }
};