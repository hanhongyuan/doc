/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Remove {
public:
    ListNode* removeNode(ListNode* pHead, int delVal) {
        ListNode * temp=pHead;

		if(pHead->val==delVal){//�����ж�ͷ�ڵ��Ƿ�ΪҪ��ɾ���ڵ�
			pHead=pHead->next;
			return pHead;
		}

		while(temp->next!=NULL){//����ɾ���ڵ�����м䲿��ʱ
			if(temp->next->val==delVal){
				temp->next=temp->next->next;
				return pHead;
			}
			temp=temp->next;
		}

		if(temp->next==NULL){//��ɾ���ڵ�Ϊβ�ڵ�ʱ
			temp=NULL;
		}

		return pHead;
    }
};