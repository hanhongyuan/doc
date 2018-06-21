public class ListNode {
	int val;
	ListNode next = null;

	ListNode(int val) {
		this.val = val;
	}
}

public class ChkIntersection {
	public boolean chkInter(ListNode head1, ListNode head2, int adjust0, int adjust1) {
		ListNode circle1 = getCircleHeadNode(head1);// ����뻷ͷ���
		ListNode circle2 = getCircleHeadNode(head2);// ����뻷ͷ���

		if (circle1 != null && circle2 != null) {// ��Ϊ��Ŀ�涨�������л��������ˣ����Բ��ÿ���else�����
			if (circle1 == circle2) {// ���뻷֮ǰ�Ѿ��ཻ �����������޻���������ཻ����
				return NocircleListIntersection(head1, head2, circle1);
			} else {// ���뻷֮���ཻ �������߲��ཻ
				ListNode cur = circle1.next;
				while (cur != circle1) {
					if (cur == circle2) {
						return true;
					}
					cur = cur.next;
				}
				return false;
			}
		}

		return false;
	}

	// ���������뻷ͷ��� ���޻��򷵻ؿ�
	public ListNode getCircleHeadNode(ListNode head) {
		ListNode slow = head;
		ListNode fast = head.next;

		while (fast != slow) {
			if (fast == null || fast.next == null) {
				return null;
			}
			fast = fast.next.next;
			slow = slow.next;
		}

		fast = head;
		slow = slow.next;

		while (fast != slow) {
			fast = fast.next;
			slow = slow.next;
		}

		return fast;
	}

	// ���޻��������ཻ�������� ֻ���ж���ֹ�ı�־�ǵ����뻷ͷ��� �����ǽڵ�Ϊ��
	public boolean NocircleListIntersection(ListNode headA, ListNode headB, ListNode circle) {
		int lena = 0;
		int lenb = 0;

		ListNode pa = headA;
		ListNode pb = headB;

		while (pa != circle) {// ע��������ֹ����
			lena++;
			pa = pa.next;
		}

		while (pb != circle) {// ע��������ֹ����
			lenb++;
			pb = pb.next;
		}

		pa = headA;
		pb = headB;
		if (lena > lenb) {
			int count = lena - lenb;
			while (count != 0) {
				pa = pa.next;
				count--;
			}
		} else {
			int count = lenb - lena;
			while (count != 0) {
				pb = pb.next;
				count--;
			}
		}

		while (pa != circle && pb != circle) {// ע��������ֹ����
			if (pa == pb) {
				return true;
			}
			pa = pa.next;
			pb = pb.next;
		}

		return false;
	}
}