/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

// �������ӵ�ʱ�����в�����ĵط������Ի�ͼ��⡣��ָofferԭ�� Ҳ���Բο���ָoffer����
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        createNode(pHead);
        generateRandom(pHead);
        return turnToTwoList(pHead);
    }
    // ��һ���� �����µ����� ��ԭ�����ÿһ���ڵ㶼����һ��ͬ���Ľڵ��ڵ�ǰ�ڵ����
    void createNode(RandomListNode* pHead)
    {
        RandomListNode* p=pHead;
 
        while(p!=NULL)
        {
            RandomListNode* node=new RandomListNode(p->label);
            node->next=p->next;
            node->random=NULL;
            p->next=node;
            p=node->next;
        }
    }

    // ���½ڵ��randomָ����и�ֵ��randomָ��ԭָ���random��next�ڵ�
    void generateRandom(RandomListNode* pHead)
    {
        RandomListNode* p=pHead;
        while(p!=NULL)
        {
            RandomListNode* cur=p->next;
            if(p->random!=NULL)// Ҫ�ж�randomָ���Ƿ�Ϊ�գ�����ֵ�ͻᱨ��
            {
                cur->random=p->random->next;
            }
            p=cur->next;
        }
    }
     // �������µ�ͷ��������������ֿ�
    RandomListNode* turnToTwoList(RandomListNode* pHead)
    {
        RandomListNode* p=pHead;
        RandomListNode* ranHead=NULL;
        RandomListNode* cur=NULL;
 
        if(p!=NULL)// ��ʼ��random��ͷ�ڵ�
        {
            ranHead=cur=p->next;
            p->next=ranHead->next;
            p=p->next;
        }
 
        while(p!=NULL)
        {
             
            cur->next=p->next;
            cur=cur->next;
            p->next=cur->next;
            p=p->next;
        }
 
        return ranHead;
    }
};