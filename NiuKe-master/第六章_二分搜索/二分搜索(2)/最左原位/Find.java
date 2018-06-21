public class Find {
	public int findPos(int[] arr, int n) {
		int low = 0;
		int high = n - 1;
		int res = -1;
		while (low <= high) {// ��������
			int mid = low + (high - low) / 2;

			if (arr[mid] == mid) {// ��i==arr[i]ʱ��¼ �±� ������벿������
				res = mid;
				high = mid - 1;
			} else if (arr[mid] > mid) {// ��Ϊ���������ظ�Ԫ������ ����ʱԪ�ش����±� ���±��������1
										// Ԫ����С�ı仯Ҳ��1�����������ٳ�����ȵ����
				high = mid - 1;
			} else {// ͬ�� ��С��Χ���Ұ벿��
				low = mid + 1;
			}
		}
		return res;
	}
}