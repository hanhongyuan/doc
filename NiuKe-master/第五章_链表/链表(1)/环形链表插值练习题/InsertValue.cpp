#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class InsertValue {
public:
    ListNode* insert(vector<int> A, vector<int> nxt, int val) {
        ListNode *root=createList(A,nxt);
 
        ListNode * pre=root;
        ListNode * cur=root->next;
         
        ListNode * node=NULL;
        while(cur!=NULL){
            if(val>=pre->val&&val<=cur->val){//val��pre��cur��val֮��Ļ� �Ͳ����µĽڵ�
                node=new ListNode(val);
                pre->next=node;
                node->next=cur;
                break;
            }
            pre=pre->next;
            cur=cur->next;
        }
 
        if(node==NULL){//˵��val���������ֵ������Сֵ
            node=new ListNode(val);
            if(pre->val<=node->val){//���ֵ�����
                pre->next=node;
                node->next=NULL;
                return root;
            }else if(node->val<=root->val){//��Сֵ�����
                node->next=root;
                pre->next=NULL;
                return node;
            }
        }
 
        return root;//��ͨ�����
    }
	//�����ʼ�������� ţ������������������ ���Թ��컷������������OJ
    ListNode * createList(vector<int> A, vector<int> nxt){
        ListNode *root=new ListNode(A[0]);
        ListNode * temp=root;
        for(int i=1;i<A.size();i++)
        {
            root->next=new ListNode(A[i]);
            root=root->next;
        }
          
        return temp;
    }
};