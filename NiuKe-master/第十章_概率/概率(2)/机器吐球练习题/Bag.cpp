/**
 * ��ˮ�س����㷨��
 * 1.����1-k����ʱ��ֱ�ӷ��������
 * 2.�����i����(��ʱi����k)��ʱ����k/i�ĸ��ʾ����Ƿ��i���������У������뻹Ҫ�ڴ���������ӵ�һ��
 * @author sony
 *
 */
class Bag {
public:
	vector<int> ret;
    // ÿ����һ���򶼻�������������N��ʾ��i�ε���
    vector<int> carryBalls(int N, int k) {
        if(N<=k){
            ret.push_back(N);
		}
        else{
            int r=rand()%N;
            //ѹ�����k/N
            if(r<k)//����ȸ����³���
                ret[r]=N;
        }
        return ret;
    }
};