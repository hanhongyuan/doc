import java.util.*;

public class RandomSeg {
    private Random rand = new Random(12345);
    public double f() {
        return rand.nextFloat();
    }
    // �����f()����ʵ��
    public double random(int k, double x) {
        double max=Double.MIN_VALUE;
        for(int i=0;i<k;i++){
            max=Math.max(max, f());
        }
        return max;
    }
}