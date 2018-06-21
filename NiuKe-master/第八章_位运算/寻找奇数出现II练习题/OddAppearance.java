import java.util.Arrays;

public class OddAppearance {
	public int[] findOdds(int[] arr, int n) {
		int e = 0;
		for (int i = 0; i < n; i++) {// ����һ�α����õ����������������������ֵ
			e = e ^ arr[i];
		}
		int flag = kpos(e);// ��õ�kλ����1��������λΪ0
		int res[] = new int[2];
		res[0] = 0;
		res[1] = 0;
		for (int i = 0; i < n; i++) {
			if ((arr[i] & flag) == flag) {// ͬ���ǵ�kλΪ1����
				res[0] = res[0] ^ arr[i];
			} else {// ��kλΪ0����
				res[1] = res[1] ^ arr[i];
			}
		}
		Arrays.sort(res);
		return res;
	}

	// ���غ�num��������iλ����1����
	public int kpos(int num) {
		int pos = 0;
		for (int i = 0; i < 32; i++) {
			pos = (1 << i);
			if ((pos & num) != 0) {
				break;
			}
		}
		return pos;
	}
}