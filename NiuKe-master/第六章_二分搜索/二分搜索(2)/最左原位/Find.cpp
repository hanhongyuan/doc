class Find {
public:
    int findPos(vector<int> arr, int n) {
        
        if(arr[0]>n-1||arr[n-1]<0)
        {
            return -1;
        }
 
        int res=-1;
 
        int low,high,middle;
 
        low=0;
        high=n-1;
 
        while(low<=high)// ��������
        {
            middle=low+(high-low)/2;
 
            if(arr[middle]==middle)// ��i==arr[i]ʱ��¼ �±� ������벿������
            {
                res=middle;
                high=middle-1;
            }
            else if(arr[middle]>middle)// ��Ϊ���������ظ�Ԫ������ ����ʱԪ�ش����±� ���±��������1 Ԫ����С�ı仯Ҳ��1�����������ٳ�����ȵ����
            {
                high=middle-1;
            }
            else if(arr[middle]<middle)// ͬ�� ��С��Χ���Ұ벿��
            {
                low=middle+1;
            }
        }
 
        return res;
    }
};