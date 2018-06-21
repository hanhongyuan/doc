public class ListNode {
	int val;
	ListNode next = null;

	ListNode(int val) {
		this.val = val;
	}
}

public class Remove {
	public ListNode removeNode(ListNode pNode, int delVal) {
		ListNode temp = pNode;

		if (pNode.val == delVal) {// �����ж�ͷ�ڵ��Ƿ�ΪҪ��ɾ���ڵ�
			pNode = pNode.next;
			return pNode;
		}

		while (temp.next != null) {// ����ɾ���ڵ�����м䲿��ʱ
			if (temp.next.val == delVal) {
				temp.next = temp.next.next;
				return pNode;
			}
			temp = temp.next;
		}

		if (temp.next == null) {// ��ɾ���ڵ�Ϊβ�ڵ�ʱ
			temp = null;
		}
		return pNode;
	}
}