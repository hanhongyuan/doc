import java.util.*;
 
public class Exchange {
   public int countWays(int[] penny, int n, int aim) {
        int dp[][] = new int[n][aim + 1];// dp[i][j] ���� ʹ��0..i�ֻ������Ǯ��j�ķ�����
 
        for (int i = 0; i < n; i++) {// ��ʼ����һ�� ���Ǯ��0�ķ�����Ϊ1
            dp[i][0] = 1;
        }
 
        for (int i = 0; i <= aim; i++) {// ��ʼ����һ�� ʹ�õ�0�ֻ������Ǯ��j�ķ�����
            if (i % penny[0] == 0) {
                dp[0][i] = 1;
            }
        }
 
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= aim; j++) {
                if (j >= penny[i]) {//��Ǯ�����ڵ�i�����ҵ���ֵʱ���п���ʹ�õ�i������
                    dp[i][j] = dp[i - 1][j] + dp[i][j - penny[i]];
		    /*�����ʽ���������ģ�
                    dp[i][j]����Դ:
                      1.ʹ��m��(m=0,1,2...)i�������j�ķ�����(ʹ��0��dp[i-1][j-0*penny[i]],ʹ��1��dp[i-1][j-1*penny[i]],ʹ��2��dp[i-1][j-2*penny[i]].....)
                       
                      ����Ĺ�ʽ��ʵ���ǰ�m=0���������˳����������dp[i][j-penny[i]]��ʾm=1��ʼ�����
                      Ϊʲôdp[i][j-penny[i]]�ܱ�ʾm=1������أ� ��ʵ�㿴���ʽ�Ӵ��ص��������ʹ��m��i�������j-penny[i]�ķ�����
                    */	
                } else {//Ǯ��С��penny[i]������ʹ��i���� ֻ��ʹ��i-1������ȥ���Ǯ��J
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
 
        return dp[n - 1][aim];
    }
}