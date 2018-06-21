
/*
public class ListNode {
	int val;
	ListNode next = null;

	ListNode(int val) {
		this.val = val;
	}
}
*/

public class ChkLoop {
	public int chkLoop(ListNode head, int adjust) {
		ListNode slow = head;// ��ָ��
		ListNode fast = head.next;// ��ָ��

		while (fast != slow) {// ��ָ��һ����2����ָ��һ����һ��
			if (fast == null || fast.next == null) {// ����ָ��Ϊ�� ˵�������л�ָ�� ����-1
				return -1;
			}
			fast = fast.next.next;
			slow = slow.next;
		}

		// ���¸�ֵ����ָ��
		fast = head;
		slow = slow.next;

		while (fast != slow) {// ������ָ���ٴ�����ʱ�����뻷��ͷ�ڵ�
			fast = fast.next;
			slow = slow.next;
		}

		return fast.val;
	}
}