class LeftMostAppearance {
public:
    int findPos(vector<int> arr, int n, int num) {
         
 
        int res=-1;
 
        int low,high,middle;
 
        low=0;
        high=n-1;
 
        while(low<=high)// ��������
        {
            middle=low+(high-low)/2;
 
            if(arr[middle]==num)// ����Ŀ��ֵ���ʱ ����res�±�
            {
                res=middle;
                high=middle-1;
            }
            else if(arr[middle]>num)
            {
                high=middle-1;
            }
            else if(arr[middle]<num)
            {
                low=middle+1;
            }
        }
 
        return res;
    }
};