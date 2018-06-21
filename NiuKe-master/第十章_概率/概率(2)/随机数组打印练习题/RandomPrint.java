import java.util.Random;

/**
 * �����ӡM���� ÿ�δ�ӡһ����֮��Ͱ�������ŵ�ĩβ����Ҫ���þ���ʹ����һ�δ�ӡʱ�������л�����֣�����ÿ��
 * ��ӡ�Ĺ����е�ÿһ�����ĸ��ʶ�����ȵ�
 * @author sony
 *
 */
public class RandomPrint {
	public int[] print(int[] arr, int N, int M) {
		int[] res = new int[M];
		Random random = new Random();
		for (int i = 0; i < M; i++) {
			int r = random.nextInt(N);
			res[i] = arr[r];
			swap(arr, r, N - 1);
			N--;
		}
		return res;
	}

	public void swap(int[] A, int a, int b) {
		int temp = A[a];
		A[a] = A[b];
		A[b] = temp;
	}
}