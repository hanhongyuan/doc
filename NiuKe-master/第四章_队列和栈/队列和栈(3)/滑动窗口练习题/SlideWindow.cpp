class SlideWindow {
public:
    vector<int> slide(vector<int> arr, int n, int w) {
        vector<int> res;
        deque<int> dq;
        for(int i=0;i<n;i++){
            if(dq.empty()||arr[dq.back()]>arr[i])//������Ϊ�ջ��߶�β�����µ�Ԫ�ش�������Ԫ�أ����������
                dq.push_back(i);
            else{
                while(!dq.empty()&&arr[dq.back()]<arr[i]){//�����һֱ����
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            if(i>=w-1){//��ֵ���ֵ����
                while(!dq.empty() && i-dq.front()>w-1)
                    dq.pop_front();
                res.push_back(arr[dq.front()]);
            }
        }
        return res;
    }
};
