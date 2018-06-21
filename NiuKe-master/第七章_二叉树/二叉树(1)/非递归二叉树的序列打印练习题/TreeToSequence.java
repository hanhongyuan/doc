import java.util.ArrayList;
import java.util.Stack;

/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;
    public TreeNode(int val) {
        this.val = val;
    }
}*/
public class TreeToSequence {
	public int[][] convert(TreeNode root) {
		int[] pre = preOrder(root);
		int[] in = Inorder(root);
		int[] rev = RevOrder(root);

		int[][] res = new int[3][pre.length];
		res[0] = pre;
		res[1] = in;
		res[2] = rev;

		return res;
	}

	// �ǵݹ�ǰ�����������
	public int[] preOrder(TreeNode root) {
		Stack<TreeNode> stack = new Stack<>();// ��һ��ջ�洢�ڵ�
		stack.push(root);

		ArrayList<Integer> value = new ArrayList<>();
		while (!stack.isEmpty()) {
			TreeNode cur = stack.peek();
			stack.pop();

			value.add(cur.val);

			if (cur.right != null) {// �ȼ����ҽڵ� ��Ϊջ���Ƚ���������ݽṹ ����������������������˳��
				stack.push(cur.right);
			}

			if (cur.left != null) {
				stack.push(cur.left);
			}
		}

		int[] res = new int[value.size()];

		for (int i = 0; i < res.length; i++) {
			res[i] = value.get(i);
		}

		return res;
	}

	// �ǵݹ��������������
	public int[] Inorder(TreeNode root) {
		Stack<TreeNode> stack = new Stack<>();
		TreeNode cur = root;

		ArrayList<Integer> value = new ArrayList<>();

		while (cur != null || !stack.isEmpty()) {
			while (cur != null) {// ���ϵĽ���ǰ�ڵ����ڵ����ջ��
				stack.push(cur);
				cur = cur.left;
			}

			if (!stack.isEmpty()) {
				TreeNode temp = stack.peek();// ����ջ���ڵ�
				stack.pop();
				value.add(temp.val);
				cur = temp.right;// ָ��ǰ�ڵ���ҽڵ�
			}
		}

		int[] res = new int[value.size()];

		for (int i = 0; i < res.length; i++) {
			res[i] = value.get(i);
		}

		return res;
	}

	// �ǵݹ�������������
	public int[] RevOrder(TreeNode root) {
		TreeNode h = root;// �������һ�δ�ӡ����Ľڵ�
		TreeNode c = null;
		Stack<TreeNode> stack = new Stack<>();

		stack.push(root);
		ArrayList<Integer> value = new ArrayList<>();
		while (!stack.isEmpty()) {
			c = stack.peek();

			if (c.left != h && c.right != h && c.left != null) {// ��ǰ�ڵ�c�����ҽڵ㶼������hͬʱ��������Ϊ�գ�˵�����ӻ�û�д�ӡ
																// ����������ջ
				stack.push(c.left);
			} else if (c.right != h && c.right != null) {// ��ǰ�ڵ�c���ҽڵ㲻����hͬʱ�ҽڵ㲻Ϊ�գ�˵���ҽڵ㻹û�д�ӡ��
															// ���԰��ҽڵ����ջ��
				stack.push(c.right);
			} else {// �����������������Ļ� ˵��Ҫ��ӡ��ǰ�ڵ��� ͬʱ��h=c ��Ϊc�ո�������
				value.add(c.val);
				stack.pop();
				h = c;
			}
		}

		int[] res = new int[value.size()];

		for (int i = 0; i < res.length; i++) {
			res[i] = value.get(i);
		}

		return res;
	}
}