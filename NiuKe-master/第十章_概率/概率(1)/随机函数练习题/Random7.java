import java.util.*;

/**
 * ������һ���������1-5�ĺ��� Ȼ������5*����+���� ����һ���������1-30֮����������
 * Ȼ�������ɵ�������7-20�ķ�Χ�ھ��ٴ�����ķ�ʽ��������������ȸ��ʵ�����������7-20�ķ�Χ��
 * ֮����%7+1���ܵȸ����������1-7��������
 * @author sony
 *
 */
public class Random7 {
    private static Random rand = new Random(123456);
    // �������[1,5]
    private int rand5() {
        return 1 + rand.nextInt(5);
    }
    
    // ͨ��rand5ʵ��rand7
    public int randomNumber() {
    	int num=rand5()*5+rand5();
    	while (num>20||num<7) {
			num=rand5()*5+rand5();
		}
    	return (num%7)+1;
    }
}