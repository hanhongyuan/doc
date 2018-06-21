/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;
    public TreeNode(int val) {
        this.val = val;
    }
}*/
public class LongestDistance {
	public int findLongest(TreeNode root) {
		int l_maxdis[] = new int[1];// ��������ڵ����󳤶�
		int ld = getDepth(root.left, l_maxdis);// ��������������
		int r_maxdis[] = new int[1];// ��������ڵ����󳤶�
		int rd = getDepth(root.right, r_maxdis);// ��������������

		return Math.max(ld + rd + 1, Math.max(l_maxdis[0], r_maxdis[0]));
	}

	public int getDepth(TreeNode root, int maxDistance[]) {
		if (root == null) {
			return 0;
		}

		int l = getDepth(root.left, maxDistance);
		int r = getDepth(root.right, maxDistance);

		maxDistance[0] = l + r + 1;// ��ڵ����󳤶�

		return Math.max(l, r) + 1;
	}
}