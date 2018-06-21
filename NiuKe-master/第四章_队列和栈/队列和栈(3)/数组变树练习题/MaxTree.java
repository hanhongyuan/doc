public class MaxTree {
	public int[] buildMaxTree(int[] A, int n) {
		int res[] = new int[n];
		for (int i = 0; i < n; i++) {// ����ÿ��ֵȥ��ȡ���
			res[i] = getIndex(i, A, n);
		}
		return res;
	}

	public int getIndex(int target, int[] A, int n) {
		int left = -1;// ��ߵ�һ���������������
		int right = n;// �ұߵ�һ���������������

		for (int i = target + 1; i < n; i++) {// ����������
			if (A[i] > A[target]) {
				right = i;
				break;
			}
		}

		for (int i = target - 1; i >= 0; i--) {// ����������
			if (A[i] > A[target]) {
				left = i;
				break;
			}
		}

		if (left == -1 && right == n) {// ������������û�仯��˵���������߶�û�б�������������ڵ㷵��-1
			return -1;
		} else if (left != -1 && right != n) {// ���������������仯�ˣ���ʱ����Ԫ�ظ�С���Ǹ�����
			return A[left] > A[right] ? right : left;
		} else if (left != -1 && right == n) {// ͬ�� �������
			return left;
		} else if (left == -1 && right != n) {// �������б仯��������û�С�˵���ұ߸�С������
			return right;
		}

		return 0;
	}
}