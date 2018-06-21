public class ListNode {
	int val;
	ListNode next = null;

	ListNode(int val) {
		this.val = val;
	}
}

public class ClearValue {
	public ListNode clear(ListNode head, int val) {
		ListNode pListNode = head;
		ListNode node = new ListNode(0);// ����һ��ָ��head��ָ��
		node.next = pListNode;
		ListNode cur = node;
		while (pListNode != null) {// �������� ɾ��Ŀ��ֵ
			if (pListNode.val == val) {
				node.next = pListNode.next;
			} else {
				node = node.next;
			}
			pListNode = pListNode.next;
		}

		return cur.next;
	}
}