
//�������Ҫע����� ţ��OJ���жϵ�ʱ���ǰ�����ʦ�Ĵ����� �����ڵ����ֿ�������������ѡ����ֵ�ʱ�� ��ο���������˳��
public class Solution {
	public int getLessIndex(int[] arr) {

		int res = -1;

		if (arr == null || arr.length == 0) {
			return res;
		}

		if (arr.length == 1) {
			return 0;
		}

		int low = 0;
		int high = arr.length - 1;
		if (low == 0 && arr[low] < arr[low + 1]) {// ������жϾֲ���С
			return 0;
		}

		if (high == arr.length - 1 && arr[high - 1] > arr[high]) {// ���ұ��жϾֲ���С
			return arr.length - 1;
		}

		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1]) {
				res = mid;
				break;
			}

			if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]) {
				high = mid;
			} else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1]) {
				low = mid;
			} else {// ��midֵ��������ʱ����С��Χ����߰벿�� ��ѡ���ұ������OJ���д�
				high = mid;
			}
		}

		return res;
	}
}