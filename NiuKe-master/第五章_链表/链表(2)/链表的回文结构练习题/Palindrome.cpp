/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        // write code here
 
        ListNode *fast=pHead;
        ListNode *slow=pHead;
 
        while(fast!=NULL&&fast->next!=NULL)// ��������ָ�� ��ָ��һ�������� ��ָ��һ����һ��
        {
            fast=fast->next->next;
            slow=slow->next;
        }
 
        ListNode *prev=NULL;
 
        while(slow!=NULL)// ��ʱ��ָ�������ģ����м俪ʼ��תʣ������
        {
            ListNode *next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }
         
        ListNode *p=pHead;
        while(prev)// �жϴ�ͷ��ʼ���м�ʹ�ĩβ��ʼ���м�������������Ƿ���ȣ��������˵���ǻ��Ľṹ
        {
            if(prev->val==p->val)
            {
                prev=prev->next;
                p=p->next;
            }
            else
            {
                return false;
            }
        }
 
        return true;
    }
};