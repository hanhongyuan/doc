import java.util.ArrayList;

public class SlideWindow {
	public int[] slide(int[] arr, int n, int w) {
		ArrayList<Integer> list = new ArrayList<>();// ˫�˶��� ���������±�����
		int[] res = new int[n - w + 1];// ������ֵ�������

		for (int i = 0; i < n; i++) {
			if (!list.isEmpty() && list.get(0) <= i - w) {// �����е�ͷԪ�س����˵�ǰ�������ڵķ�Χʱ�����Ƴ���
				list.remove(0);
			}

			while (!list.isEmpty() && arr[list.get(list.size() - 1)] < arr[i]) {// ��ǰ���еĶ�βԪ�ص�ֵС������ֵ���Ƴ���βԪ��
				list.remove(list.size() - 1);
			}

			if (list.isEmpty() || arr[list.get(list.size() - 1)] > arr[i]) {// ��βԪ�ش�������Ԫ�أ����뵱ǰ����
				list.add(i);
			}

			if (i >= w - 1) {// ��ֵ���ֵ
				res[i - w + 1] = arr[list.get(0)];
			}
		}

		return res;
	}
}