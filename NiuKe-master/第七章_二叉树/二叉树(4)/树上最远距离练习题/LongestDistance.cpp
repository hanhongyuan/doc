/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
 
class LongestDistance {
public:
    int findLongest(TreeNode* root) {
        
       int lmax1=0;// ��������ڵ����󳤶�
       int lres=getMaxHeight(root->left,lmax1);// ��������������
     
       int rmax1=0;// ��������ڵ����󳤶�
       int rres=getMaxHeight(root->right,rmax1);// ��������������
         
             
       return max(lres+rres+1,max(lmax1,rmax1));
    }
     
 
    int max(int a,int b)
    {
        return a>b?a:b;
    }
     
    int getMaxHeight(TreeNode* root,int &maxDistance)
    {
        if(root==NULL)
        {
            return 0;
        }
         
         
        int lh=getMaxHeight(root->left,maxDistance);
        int rh=getMaxHeight(root->right,maxDistance);
 
        maxDistance=lh+rh+1;// ��ڵ����󳤶�
        return max(lh,rh)+1;
    }
};;