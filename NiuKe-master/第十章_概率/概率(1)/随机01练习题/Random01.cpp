#include <iostream>
#include <string>
using namespace std;


class RandomP {
public:
	static int f();
};

/**
 * ��ΪҪ�ȸ��ʲ���01 ��p���ʲ���0 1-p����1 ��ô�����߸�����˾�����ȵ� ����01��10�ĳ��ֵĸ��ʶ���p*(1-p)
 * ��ʱ���ɺ�������01����10����
 * @author sony
 *
 */
class Random01 {
public:
    // ��RandomP::f()ʵ�ֵȸ��ʵ�01����
    int random01() {
        int n1;
        int n2;
        while(true){
            n1 = RandomP::f();
            n2 = RandomP::f();
            if(n1==n2)continue;
            else if(n1==1&&n2==0)return 1;
            else break;
        }
        return 0;
    }
     
};