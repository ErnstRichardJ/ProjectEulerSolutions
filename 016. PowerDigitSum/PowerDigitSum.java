import java.math.BigInteger;

public class PowerDigitSum {
    public static void main(String[] args) {
        BigInteger x = BigInteger.TWO.pow(1000);
        
        int sum = 0;

        while (x.compareTo(BigInteger.ZERO) == 1) {
            sum += x.mod(BigInteger.TEN).intValue();
            x = x.divide(BigInteger.TEN);
        }

        System.out.println(sum);
    }
}
