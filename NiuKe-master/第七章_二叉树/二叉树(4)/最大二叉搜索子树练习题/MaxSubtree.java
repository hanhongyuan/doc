/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;
    public TreeNode(int val) {
        this.val = val;
    }
}*/
public class MaxSubtree {
	public TreeNode getMax(TreeNode root) {
		int[] value = new int[3];
		return RevOrder(root, value);
	}

	public TreeNode RevOrder(TreeNode root, int[] value) {
		if (root == null) {
			value[0] = Integer.MIN_VALUE;// 0������ֵ��1�����Сֵ��2����ܽ����
			value[1] = Integer.MAX_VALUE;
			value[2] = 0;

			return null;
		}

		TreeNode l_Node = RevOrder(root.left, value);// �������ڵ��Լ������Ϣ
		int l_max = value[0];
		int l_min = value[1];
		int l_num = value[2];
		TreeNode r_Node = RevOrder(root.right, value);// �������ڵ��Լ������Ϣ
		int r_max = value[0];
		int r_min = value[1];
		int r_num = value[2];

		int cur_val = root.val;// ��ǰ�ڵ�ֵ

		value[0] = Math.max(r_max, cur_val);// �������ֵ
		value[1] = Math.min(l_min, cur_val);// ������Сֵ

		// �����ǰ�ڵ�������ӵ����ֵ С���Һ��ӵ���Сֵ ���������ڵ�Ҳ�Ƕ���������
		if (l_Node == root.left && r_Node == root.right && l_max < root.val && r_min > root.val) {
			value[2] = r_num + l_num + 1;// ���½ڵ����
			return root;// ����ͷ�ڵ�
		}

		value[2] = Math.max(r_num, l_num);// ˵����������������� ѡ�����ҽڵ��н϶�ڵ���������½ڵ����

		return r_num >= l_num ? r_Node : l_Node;// ���ؽڵ��������������ͷ�ڵ�
	}
}