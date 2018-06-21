class ListNode {
	int val;
	ListNode next = null;

	ListNode(int val) {
		this.val = val;
	}
}

public class InsertValue {
	public ListNode insert(int[] A, int[] nxt, int val) {
		ListNode root = createList(A, nxt);
		ListNode pre = root;
		ListNode cur = root.next;

		ListNode node = null;
		while (cur != null) {
			if (pre.val <= val && val <= cur.val) {// val��pre��cur��val֮��Ļ�
													// �Ͳ����µĽڵ�
				node = new ListNode(val);
				pre.next = node;
				node.next = cur;
				break;
			}
			pre = pre.next;
			cur = cur.next;
		}

		if (node == null) {// ˵��val���������ֵ������Сֵ
			node = new ListNode(val);
			if (pre.val <= node.val) {// ���ֵ�����
				pre.next = node;
				node.next = null;
				return root;
			} else if (node.val <= root.val) {// ��Сֵ�����
				pre.next = null;
				node.next = root;
				return node;
			}
		}

		return root;// ��ͨ�����
	}

	// �����ʼ�������� ţ������������������ ���Թ��컷������������OJ
	public ListNode createList(int[] A, int[] nxt) {
		ListNode root = new ListNode(A[0]);
		ListNode temp = root;
		for (int i = 1; i < A.length; i++) {
			root.next = new ListNode(A[i]);
			root = root.next;
		}
		return temp;
	}
}