import java.util.ArrayList;

/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;
    public TreeNode(int val) {
        this.val = val;
    }
}*/
public class FindErrorNode {
	public int[] findError(TreeNode root) {
		ArrayList<Integer> list = new ArrayList<>();
		Inorder(root, list);
		int time = 0;
		int pos1 = 0;// λ��1
		int pos2 = 0;// λ��2
		for (int i = 1; i < list.size(); i++) {
			if (list.get(i) < list.get(i - 1) && time == 0) {// �����ֵ�һ�ν�����̵�ʱ��
				pos1 = i - 1;// ȡ�ϴ���Ǹ�Ԫ��
				time++;
			} else if (list.get(i) < list.get(i - 1) && time == 1) {// ���ڶ��γ��ֽ�����̵�ʱ��
				pos2 = i;// ȡ��С���Ǹ�Ԫ��
				time++;
			}
		}
		int[] res = new int[2];// ֵ�Ĵ�С˳��������

		if (time == 2) {// ��2�ν������ ��Ӧ��2��λ�ó���
			res[0] = list.get(pos2);
			res[1] = list.get(pos1);
		} else if (time == 1) {// ��1�ν������ ��Ӧ����ֻ��һ��λ��
			res[0] = list.get(pos1 + 1);
			res[1] = list.get(pos1);
		}
		return res;
	}

	// ����������Ԫ�ص�����
	public void Inorder(TreeNode root, ArrayList<Integer> res) {
		if (root == null) {
			return;
		}

		Inorder(root.left, res);
		res.add(root.val);
		Inorder(root.right, res);
	}
}