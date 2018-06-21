public class MinValue {
	public int getMin(int[] arr, int n) {
		int low = 0;
		int high = n - 1;
		int res = 0;

		while (low <= high) {
			if (arr[low] < arr[high]) {// ��high����low ˵����low��high֮����������
										// ��ʱ����low��ֵ��Ϊ��Сֵ
				res = arr[low];
				break;
			} else {

				if (high - low == 1) {// ��������ֻ������Ԫ��ʱ ����С���Ǹ�
					return Math.min(arr[low], arr[high]);
				}

				int mid = low + (high - low) / 2;
				if (arr[mid] > arr[high]) {// ���м�ֵ�������ұߵ�ֵʱ ��Сֵ�������ұ�
					low = mid;
				} else if (arr[mid] < arr[low]) {// ���м�ֵС�������ֵ��ʱ�� ��Сֵ���������
					high = mid;
				} else {// �����������ϵ���� ��˵�� low mid high �������
						// ��ʱͨ������low��high֮���ֵ�������Сֵ
					res = getMin(arr, low, high);
					break;
				}
			}
		}

		return res;

	}

	public int getMin(int[] arr, int low, int high) {
		int min = arr[low];
		for (int i = low; i <= high; i++) {
			if (arr[i] < min) {
				min = arr[i];
			}
		}
		return min;
	}
}