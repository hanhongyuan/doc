/**
 * �����ӡM���� ÿ�δ�ӡһ����֮��Ͱ�������ŵ�ĩβ����Ҫ���þ���ʹ����һ�δ�ӡʱ�������л�����֣�����ÿ��
 * ��ӡ�Ĺ����е�ÿһ�����ĸ��ʶ�����ȵ�
 * @author sony
 *
 */
class RandomPrint {
public:
    vector<int> print(vector<int> arr, int N, int M) {
        vector<int> res;
		for(int i=0;i<M;i++){
			int r=rand()%(N);
			res.push_back(arr[r]);
			swap(arr[r],arr[N-1]);
			N--;
		}
		return res;
    }

};