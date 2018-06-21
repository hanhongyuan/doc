import niuke.������_����.����(3).��������ĸ�����ϰ��.RandomListNode;

/*
public class RandomListNode {
	int label;
	RandomListNode next = null;
	RandomListNode random = null;

	RandomListNode(int label) {
		this.label = label;
	}
}
*/

// �������ӵ�ʱ�����в�����ĵط������Ի�ͼ��⡣��ָofferԭ�� Ҳ���Բο���ָoffer����
public class Solution {
	public RandomListNode Clone(RandomListNode pHead) {
		pHead = createRandomNode(pHead);
		pHead = linkRandomNode(pHead);
		return split_twoList(pHead);
	}

	// ��һ���� �����µ����� ��ԭ�����ÿһ���ڵ㶼����һ��ͬ���Ľڵ��ڵ�ǰ�ڵ����
	public RandomListNode createRandomNode(RandomListNode phead) {
		RandomListNode pListNode = phead;
		while (pListNode != null) {
			RandomListNode node = new RandomListNode(pListNode.label);
			node.random = null;
			node.next = pListNode.next;
			pListNode.next = node;
			pListNode = node.next;
		}

		return phead;
	}

	// ���½ڵ��randomָ����и�ֵ��randomָ��ԭָ���random��next�ڵ�
	public RandomListNode linkRandomNode(RandomListNode phead) {
		RandomListNode pListNode = phead;
		while (pListNode != null) {
			RandomListNode node = pListNode.next;
			if (pListNode.random != null) {// Ҫ�ж�randomָ���Ƿ�Ϊ�գ�����ֵ�ͻᱨ��
											// Ϊ�վ�ֱ�Ӳ��ø�ֵ��
				node.random = pListNode.random.next;
			}
			pListNode = node.next;
		}
		return phead;
	}

	// �������µ�ͷ��������������ֿ�
	public RandomListNode split_twoList(RandomListNode phead) {
		RandomListNode ranHead = null;
		RandomListNode p = phead;
		RandomListNode cur = null;

		if (p != null) {// ��ʼ��random��ͷ�ڵ�
			ranHead = cur = p.next;
			p.next = ranHead.next;
			p = p.next;
		}

		while (p != null) {
			cur.next = p.next;
			cur = cur.next;
			p.next = cur.next;
			p = p.next;
		}

		return ranHead;
	}
}