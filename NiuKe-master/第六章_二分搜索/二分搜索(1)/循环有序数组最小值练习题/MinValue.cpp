int min(int a,int b)
{
    return a>b?b:a;
}
 
 
 
class MinValue {
public:
    int getMin(vector<int> arr, int n) {
        
        if(n==1)
        {
            return arr[0];
        }
 
        int low,high,middle;
         
        low=0;
        high=n-1;
 
        if(arr[low]<arr[high])// ��high����low ˵����low��high֮���������� ��ʱ����low��ֵ��Ϊ��Сֵ
        {
            return arr[low];
        }
 
        int res=0;
        while(low<=high)
        {
            middle=low+(high-low)/2;
 
            if(high-low==1)// ��������ֻ������Ԫ��ʱ ����С���Ǹ�
            {
               res=min(arr[high],arr[low]);
               break;
            }
             
            if(arr[middle]<arr[low])// ���м�ֵС�������ֵ��ʱ�� ��Сֵ���������
            {
                high=middle;
            }
            else if(arr[middle]>arr[high])// ���м�ֵ�������ұߵ�ֵʱ ��Сֵ�������ұ�
            {
                low=middle;
            }
            else if(arr[middle]>=arr[low]&&arr[middle]<=arr[high])//�����������ϵ���� ��˵�� low mid high ������� ��ʱͨ������low��high֮���ֵ�������Сֵ
            {
                res=arr[low];
                for(int j=low;j<=high;j++)
                {
                    if(arr[j]<res)
                    {
                        res=arr[j];
                    }
                }
                break;
            }
        }
 
        return res;
    }
};