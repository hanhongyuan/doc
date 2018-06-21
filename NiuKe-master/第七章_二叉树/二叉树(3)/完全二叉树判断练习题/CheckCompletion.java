import java.util.LinkedList;
import java.util.Queue;

/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;
    public TreeNode(int val) {
        this.val = val;
    }
}*/
public class CheckCompletion {
	public boolean chk(TreeNode root) {
		Queue<TreeNode> queue = new LinkedList<>();
		queue.add(root);
		boolean res = true;
		boolean isleaf = false;
		while (!queue.isEmpty()) {// ������������м���
			TreeNode cur = queue.poll();

			if (isleaf) {// ����־Ϊtrueʱ ����ʼ�жϵ�ǰ�ڵ��Ƿ�ΪҶ�ӽڵ�
				if (!(cur.right == null && cur.left == null)) {// ����Ҷ�ӽڵ� ����
																// false
					res = false;
					break;
				}
			}

			if (cur.right != null && cur.left == null) {// ���Һ���û���� ��������ȫ����������
														// ����false
				res = false;
				break;
			} else if (cur.right != null && cur.left != null) {
				queue.add(cur.left);
				queue.add(cur.right);
			} else {// ����ͬʱ�������Һ���ʱ ��ʱ��Ҫ��˽ڵ��Ժ�Ľڵ㶼Ҫ��Ҷ�ӽڵ�
				isleaf = true;
				if (cur.left != null) {
					queue.add(cur.left);
				}
				if (cur.right != null) {
					queue.add(cur.right);
				}
			}

		}

		return res;
	}
}