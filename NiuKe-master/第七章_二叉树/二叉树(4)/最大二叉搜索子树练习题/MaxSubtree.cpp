/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
 
class MaxSubtree {
public:
    TreeNode* getMax(TreeNode* root) {
         
        int max,min,nums;
 
        return MaxSearchNode(root, max,  min, nums);
    }
     
    int max(int a,int b)
    {
        return a>b?a:b;
    }
 
    int min(int a,int b)
    {
        return a>b?b:a;
    }
 
    TreeNode * MaxSearchNode(TreeNode * root,int &maxNode,int &minNode,int &totalNode)
    {
        if(root==NULL)
        {
            maxNode=-9999;
            minNode=9999;
            totalNode=0;
            return NULL;
        }
 
        int lmax,lmin,lnum;
        TreeNode * lnode=MaxSearchNode(root->left,lmax,lmin,lnum);// �������ڵ��Լ������Ϣ
 
        int rmax,rmin,rnum;
        TreeNode * rnode=MaxSearchNode(root->right,rmax,rmin,rnum);// �������ڵ��Լ������Ϣ

 
        maxNode=max(rmax,root->val);// �������ֵ
        minNode=min(lmin,root->val);// ������Сֵ
 	// �����ǰ�ڵ�������ӵ����ֵ С���Һ��ӵ���Сֵ ���������ڵ�Ҳ�Ƕ���������
        if(lmax<root->val&&rmin>root->val&&lnode==root->left&&rnode==root->right)
        {
            totalNode=lnum+rnum+1;// ���½ڵ����
            return root;// ����ͷ�ڵ�
        }
 
        if(lnum>rnum)// ˵����������������� ѡ�����ҽڵ��н϶�ڵ���������½ڵ����
        {
            totalNode=lnum;
            return lnode;
        }
        else
        {
            totalNode=rnum;
            return rnode;
        }
    }
};