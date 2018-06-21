/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class ChkLoop {
public:
    int chkLoop(ListNode* head, int adjust) {
        // write code here
         
        if(head==NULL)
        {
            return -1;
        }
 
        ListNode *fast=head->next;// ��ָ��
        ListNode *slow=head;// ��ָ��
 
        while(fast!=slow)// ��ָ��һ����2����ָ��һ����һ��
        {
            if(fast==NULL||fast->next==NULL)// ����ָ��Ϊ�� ˵�������л�ָ�� ����-1
            {
                return -1;
            }
            fast=fast->next->next;
            slow=slow->next;
        }
 
	// ���¸�ֵ����ָ��
        fast=head;
        slow=slow->next;
 
        while(fast!=slow)// ������ָ���ٴ�����ʱ�����뻷��ͷ�ڵ�
        {
            fast=fast->next;
            slow=slow->next;
        }
 
        return fast->val;
    }
};