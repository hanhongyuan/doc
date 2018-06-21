/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class CheckIntersect {
public:
    bool chkIntersect(ListNode* headA, ListNode* headB) {
        // write code here
        int lena=0;
        int lenb=0;
         
        ListNode *p1=headA;
        ListNode *p2=headB;
 
        while(p1!=NULL)// ����A����ĳ���
        {
            lena++;
            p1=p1->next;
        }
 
        while(p2!=NULL)// ����B����ĳ���
        {
            lenb++;
            p2=p2->next;
        }
         
        p1=headA;
        p2=headB;
 
        if(lena>lenb)// ���ϳ��������ȱ����������Ȳ���ڵ� ��Ϊ�����������Ҫ�ཻ �϶����ཻ�ڶ�������  ���������Ͳ������������
        {
            int t=lena-lenb;// �����Ȳ�
            while(t--)
            {
                p1=p1->next;
            }
        }
        else
        {
            int t=lenb-lena;
            while(t--)
            {
                p2=p2->next;
            }
        }
 
        while(p1!=NULL&&p2!=NULL)
        {
            if(p1==p2)//�ж������ڵ� ������ֵ ֮ǰд��p1->val p2->val �������
            {
                return true;
            }
            p1=p1->next;
            p2=p2->next;
        }
 
        return false;
 
    }
};