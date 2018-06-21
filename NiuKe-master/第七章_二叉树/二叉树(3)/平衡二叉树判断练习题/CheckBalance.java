/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;
    public TreeNode(int val) {
        this.val = val;
    }
}*/
public class CheckBalance {
	public boolean check(TreeNode root) {
		return chk(root) >= 0;
	}

	public int chk(TreeNode root) {// ʹ�ú������
		if (root == null) {
			return 0;
		}
		int l = chk(root.left);// �������߶�
		int r = chk(root.right);// �������߶�

		if (l < 0 || r < 0) {// ��Ϊ-1 ��˵����������Ϊ��ƽ�������
			return -1;
		}

		if (Math.abs(l - r) > 1) {// �������������Ƿ�ƽ������� ��ʱ�ж����������ĸ߶Ȳ� ����1 ���Ƿ�ƽ������� ����
			return -1;
		}

		return Math.max(l, r) + 1;// ���������߶�
	}
}