/*
public class ListNode {
	int val;
	ListNode next = null;

	ListNode(int val) {
		this.val = val;
	}
}
*/

public class CheckIntersect {
	public boolean chkIntersect(ListNode headA, ListNode headB) {
		int lena = 0;
		int lenb = 0;

		ListNode pa = headA;
		ListNode pb = headB;

		while (pa != null) {// ����A����ĳ���
			lena++;
			pa = pa.next;
		}

		while (pb != null) {// ����B����ĳ���
			lenb++;
			pb = pb.next;
		}

		if (lena > lenb) {// ���ϳ��������ȱ����������Ȳ���ڵ� ��Ϊ�����������Ҫ�ཻ �϶����ཻ�ڶ�������
							// ���������Ͳ������������
			pa = headA;
			pb = headB;
			int count = lena - lenb;// �����Ȳ�
			while (count != 0) {
				pa = pa.next;
				count--;
			}
		} else {
			pa = headA;
			pb = headB;
			int count = lenb - lena;
			while (count != 0) {
				pb = pb.next;
				count--;
			}

		}

		while (pa != null && pb != null) {
			if (pa == pb) {
				return true;
			}
			pa = pa.next;
			pb = pb.next;
		}
		return false;
	}
}