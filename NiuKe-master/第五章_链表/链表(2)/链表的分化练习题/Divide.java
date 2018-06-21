class ListNode {
	int val;
	ListNode next = null;

	ListNode(int val) {
		this.val = val;
	}
}

// ����� ţ��������Ŀû�н������ ���¿��ܻ����������Ȼ��ͨ����OJ ��ͨ��OJ������� �� ���� С�� ���ڵ�˳���������
public class Divide {
	public ListNode listDivide(ListNode head, int val) {
		ListNode smallHead = new ListNode(-1);// �ֱ𴴽����� ���� С������ͷ���
		ListNode equalHead = new ListNode(-1);
		ListNode bigHead = new ListNode(-1);

		ListNode smalltemp = smallHead;// ���������ڵ�ı任�ڵ�
		ListNode equaltemp = equalHead;
		ListNode bigtemp = bigHead;
		ListNode temp = null;
		while (head != null) {

			temp = head;// ����ʹ��һ��temp������head������temp��nextָ��Ϊ��
						// ����Ϊ���ֱ�Ӹ�ֵhead�����head��nextһ��Ӱ���ȥ
			head = head.next;
			temp.next = null;

			if (temp.val < val) {
				smalltemp.next = temp;
				smalltemp = smalltemp.next;
			} else if (temp.val == val) {
				equaltemp.next = temp;
				equaltemp = equaltemp.next;
			} else {
				bigtemp.next = temp;
				bigtemp = bigtemp.next;
			}
		}

		if (smallHead.next == null) {// ��������û��С��Ŀ��ֵ�Ľڵ�ʱ
			equaltemp.next = bigHead.next;

		} else {
			equaltemp.next = smallHead.next;
			smalltemp.next = bigHead.next;

		}
		return equalHead.next;
	}
}