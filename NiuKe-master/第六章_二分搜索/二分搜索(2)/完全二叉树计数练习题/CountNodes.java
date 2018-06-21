public class TreeNode {
	int val = 0;
	TreeNode left = null;
	TreeNode right = null;

	public TreeNode(int val) {
		this.val = val;
	}
}

public class CountNodes {
	public int count(TreeNode root) {
		int res = 0;

		while (root.left != null && root.right != null) {
			int leftdepth = getDepth(root.left);
			int rightdepth = getDepth(root.right);

			if (leftdepth != rightdepth) {// �Ƚ�����ͷ�ڵ����� ����һ�� ˵�� ��������һ����������
											// ֱ���ù�ʽ����ڵ�
				res += Math.pow(2, rightdepth) - 1;
				res += 1;// ����ͷ�ڵ�
				root = root.left;
			} else {// ��һ��˵����������һ���������� ֱ���ù�ʽ����ڵ�
				res += Math.pow(2, leftdepth) - 1;
				res += 1;// ����ͷ�ڵ�
				root = root.right;
			}
		}

		if (root.left != null && root.right == null) {// ����ʱ��ͷ�ڵ�ֻ����������ʱ�� ��+2���ڵ�
			res += 2;
		}
		if (root.left == null && root.right == null) {// ��ֻ�и��ڵ�ʱ ��+1���ڵ�
			res += 1;
		}
		return res;
	}

	// ����������������
	public int getDepth(TreeNode head) {
		int res = 0;
		while (head != null) {
			head = head.left;
			res++;
		}
		return res;
	}
}