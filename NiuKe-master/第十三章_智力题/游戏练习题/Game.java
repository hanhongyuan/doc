import java.util.*;

/**
 * ���к��ж���ż����ʱ B��ʤ ����A��ʤ
 * @author sony
 *
 */
public class Game {
    public char getWinner(int n, int m) {
    	if ((n-1)%2==0&&(m-1)%2==0) {
			return 'B';
		}else {
			return 'A';
		}
    }
}