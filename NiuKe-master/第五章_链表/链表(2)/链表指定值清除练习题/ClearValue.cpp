/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class ClearValue {
public:
    ListNode* clear(ListNode* head, int val) {
        
       ListNode *node=new ListNode(0);// ����һ��ָ��head��ָ��
       node->next=head;
       ListNode *p=node;
        ListNode *cur=head;
       while(cur!=NULL)// �������� ɾ��Ŀ��ֵ
       {
           if(cur->val==val)
           {
              p->next=cur->next;
           }
           else
           {
               p=p->next;
           }
           cur=cur->next;
       }
 
       return node->next;
        
    }
}