/**
 * ���к��ж���ż����ʱ B��ʤ ����A��ʤ
 * @author sony
 *
 */
class Game {
public:
    char getWinner(int n, int m) {
        if((n-1)%2==0&&(m-1)%2==0){
			return 'B';
		}else{
			return 'A';
		}
    }
};