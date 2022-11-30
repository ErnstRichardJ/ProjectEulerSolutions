import java.math.BigInteger;

public class SelfPowers {
    public static void main(String[] args) {
        BigInteger sum = BigInteger.ONE;

        for (int i = 2; i <= 1000; i++) {
            sum = sum.add(BigInteger.valueOf(i).pow(i));
        }
        
        System.out.println(sum.mod(BigInteger.TEN.pow(10)));
    }
}