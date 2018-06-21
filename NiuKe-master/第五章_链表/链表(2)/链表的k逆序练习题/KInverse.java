public class ListNode {
	int val;
	ListNode next = null;

	ListNode(int val) {
		this.val = val;
	}
}

public class KInverse {
	public ListNode inverse(ListNode head, int k) {
		ListNode cur = head;
		int count = 0;
		while (cur != null && count != k) {
			cur = cur.next;
			count++;
		}
		// ��ʱcurΪ��k+1���ڵ�
		if (count == k) {
			cur = inverse(cur, k);// �ݹ麯�� ÿ�η�����һ�ε�ͷ���
			while (count-- > 0) {// ��ͼ�����������ת����
				ListNode tmp = head.next;
				head.next = cur;
				cur = head;
				head = tmp;
			}
			// curΪ��ת��ĵ�һ���ڵ�
			head = cur;
		}
		return head;
	}
}