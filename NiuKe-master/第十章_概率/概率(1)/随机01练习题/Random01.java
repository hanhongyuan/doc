import java.util.Random;

/**
 * ��ΪҪ�ȸ��ʲ���01 ��p���ʲ���0 1-p����1 ��ô�����߸�����˾�����ȵ� ����01��10�ĳ��ֵĸ��ʶ���p*(1-p)
 * ��ʱ���ɺ�������01����10����
 * @author sony
 *
 */
public class Random01 {
	private static double p = new Random().nextFloat();

	// �������p
	public static int f() {
		return new Random().nextFloat() < p ? 0 : 1;
	}

	public int random01() {
		// ͨ��f����ʵ��01�ȸ��ʷ���
		StringBuilder builder = new StringBuilder();
		while (true) {
			String string = builder.append(f()).append(f()).toString();
			if (string.equals("01")) {
				return 0;
			}
			if (string.equals("10")) {
				return 1;
			}
			builder = new StringBuilder();
		}
	}
}