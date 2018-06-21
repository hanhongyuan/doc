public class ListNode {
	int val;
	ListNode next = null;

	ListNode(int val) {
		this.val = val;
	}
}

public class Palindrome {
	public boolean isPalindrome(ListNode pHead) {
		ListNode pfast = pHead;
		ListNode pslow = pHead;

		while (pfast != null && pfast.next != null) {// ��������ָ�� ��ָ��һ�������� ��ָ��һ����һ��
			pfast = pfast.next.next;
			pslow = pslow.next;
		}

		ListNode prev = null;

		while (pslow != null) {// ��ʱ��ָ�������ģ����м俪ʼ��תʣ������
			ListNode next = pslow.next;
			pslow.next = prev;
			prev = pslow;
			pslow = next;
		}

		ListNode pNode = pHead;
		while (prev != null) {// �жϴ�ͷ��ʼ���м�ʹ�ĩβ��ʼ���м�������������Ƿ���ȣ��������˵���ǻ��Ľṹ
			if (pNode.val == prev.val) {
				pNode = pNode.next;
				prev = prev.next;
			} else {
				return false;
			}
		}

		return true;
	}
}