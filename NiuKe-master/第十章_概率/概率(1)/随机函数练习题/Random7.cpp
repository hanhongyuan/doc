/**
 * ������һ���������1-5�ĺ��� Ȼ������5*����+���� ����һ���������1-30֮����������
 * Ȼ�������ɵ�������7-20�ķ�Χ�ھ��ٴ�����ķ�ʽ��������������ȸ��ʵ�����������7-20�ķ�Χ��
 * ֮����%7+1���ܵȸ����������1-7��������
 * @author sony
 *
 */
// ���������벻Ҫ�޸�
class Random5 {
public:
	static int randomNumber();
};

class Random7 {
public:
    int rand5() {
        return Random5::randomNumber();
    }
    // ���������벻Ҫ�޸�
    

    int randomNumber() {
        int num=rand5()*5+rand5();
		while(num>20||num<7){
			num=rand5()*5+rand5();
		}
		return (num%7)+1;
	}
};