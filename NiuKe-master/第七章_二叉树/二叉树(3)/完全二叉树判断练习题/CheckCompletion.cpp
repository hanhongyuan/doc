/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class CheckCompletion {
public:
    bool chk(TreeNode* root) {
       queue<TreeNode*>s;
       s.push(root);
       bool res=true;
       bool isleaf=false;
       while(!s.empty()){// ������������м���
           TreeNode *temp=s.front();
           s.pop();
           if(isleaf){// ����־Ϊtrueʱ ����ʼ�жϵ�ǰ�ڵ��Ƿ�ΪҶ�ӽڵ�
               if(!(temp->left==NULL&&temp->right==NULL)){// ����Ҷ�ӽڵ� ���� false
		    res=false;
                    break;
               }
           }
           if(temp->right!=NULL&&temp->left==NULL){// ���Һ���û���� ��������ȫ���������� ����false
		res=false;
               	break;
           }else if(temp->right!=NULL&&temp->left!=NULL){
		s.push(temp->left);
            	s.push(temp->right);
           }else{// ����ͬʱ�������Һ���ʱ ��ʱ��Ҫ��˽ڵ��Ժ�Ľڵ㶼Ҫ��Ҷ�ӽڵ�
               isleaf=true;
               if(temp->left!=NULL){
                   s.push(temp->left);
               }
               if(temp->right!=NULL){
                   s.push(temp->right);
               }
           }
       }
        return res;
    }
};