/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class KInverse {
public:
    ListNode* inverse(ListNode* head, int k) {
        
        ListNode *p=head;
        int i,j;
        for( i=0;i<k;i++)//�ȼ��һ�����������������k�Ϳ���ֱ�ӷ�����
        {
            if(p==NULL)
            {
                return head;
            }
            p=p->next;
        }
         
        int count=0;
        p=head;
        while(p!=NULL)//��������ĳ���count
        {
            p=p->next;
            count++;
        }
        //�ⲿ�����ص� ����뻭ͼȥ��� ��֪�����ָ�����ӵĹ���
        ListNode *node=new ListNode(0);
        node->next=head;
        ListNode *pre=node;
        ListNode *cur=head;
        ListNode *temp=head->next;
         
        for(i=0;i<count/k;i++)//�ܹ���Ҫ��ת�Ĵ���
        {
            for(j=0;j<k-1;j++)//��ת����
            {
                cur->next=temp->next;
                temp->next=pre->next;
                pre->next=temp;
                temp=cur->next;
            }
            pre=cur;
            cur=cur->next;
            temp=cur->next;
        }
 
        return node->next;
    }
 
};