public class LeftMostAppearance {
	public int findPos(int[] arr, int n, int num) {
		int res = -1;
		int low = 0;
		int high = n - 1;
		while (low <= high) {// ��������
			int mid = low + (high - low) / 2;

			if (arr[mid] == num) {// ����Ŀ��ֵ���ʱ ����res�±�
				res = mid;
				high = mid - 1;
			} else if (arr[mid] > num) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		return res;
	}
}