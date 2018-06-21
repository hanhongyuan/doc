import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
public class TreeNode {
	int val = 0;
	TreeNode left = null;
	TreeNode right = null;

	public TreeNode(int val) {
		this.val = val;
	}
}
*/

public class TreePrinter {
	public int[][] printTree(TreeNode root) {
		if (root == null) {
			return null;
		}
		TreeNode last = root;
		TreeNode nlast = null;
		List<ArrayList<Integer>> list = new ArrayList();// ����һ��װ��Arraylist�ļ���list
		ArrayList<Integer> int_list = new ArrayList();// ����һ��װ���������ֵ�����
		Queue<TreeNode> queue = new LinkedList();// ����һ������ ʹ��ջ�Ͳ�����
		queue.offer(root);
		while (!queue.isEmpty()) {
			TreeNode temp = queue.poll();
			int_list.add(temp.val);
			if (temp.left != null) {// �ѵ�ǰ�ڵ���ڵ��������� ע��������Ƚ��ȳ������ݽṹ �����ӡ��Ҫ���Ǵ�����
									// ����Ҫע�����ҽڵ������е�˳��
				queue.offer(temp.left);
				nlast = temp.left;
			}
			if (temp.right != null) {// �ѵ�ǰ�ڵ��ҽڵ���������
				queue.offer(temp.right);
				nlast = temp.right;
			}
			if (last == temp) {// ����һ�е�ĩβ
				list.add(int_list);
				int_list = new ArrayList();
				last = nlast;// ����last
			}
		}
		int[][] result = new int[list.size()][];
		int count = 0;
		for (int i = 0; i < list.size(); i++) {// ��ֵ������������
			int_list = list.get(i);
			result[i] = new int[int_list.size()];
			for (int j = 0; j < int_list.size(); j++) {
				if (count <= 500) {
					result[i][j] = int_list.get(j);
					count++;
				}

			}
		}
		return result;
	}
}