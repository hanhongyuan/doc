
//�������Ҫע����� ţ��OJ���жϵ�ʱ���ǰ�����ʦ�Ĵ����� �����ڵ����ֿ�������������ѡ����ֵ�ʱ�� ��ο���������˳��
class Solution {
public:
    int getLessIndex(vector<int> arr) {
        if(arr.size()==0)
        {
            return -1;
        }
         
        int len=arr.size();
 
        if(arr.size()==1)
        {
            return 0;
        }
        else
        {
            if(arr[1]>arr[0])// ������жϾֲ���С
            {
                return 0;
            }
            if(arr[len-2]>arr[len-1])// ���ұ��жϾֲ���С
            {
                return  len-1;
            }
        }
 
        int low,high,middle;
         
        low=0;
        high=len-1;
        while(low<high)
        {
            middle=low+(high-low)/2;
 
            if(arr[middle-1]>arr[middle]&&arr[middle+1]>arr[middle])
            {
                return middle;
            }
 
            if(arr[middle]>arr[middle-1])// ����ѡ����С��Χ����߰벿�� ��ѡ���ұ������OJ���д�
            {
                high=middle;
            }
            else if(arr[middle]>arr[middle+1])
            {
                low=middle;
            }
        }
 
        return -1;
    }
};