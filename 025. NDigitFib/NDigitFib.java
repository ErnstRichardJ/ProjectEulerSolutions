import java.math.BigInteger;

public class NDigitFib {
    public static void main(String[] args) {
        BigInteger f1 = BigInteger.ONE;
        BigInteger f2 = BigInteger.ONE;
        BigInteger temp;

        int i = 2;

        while (f2.toString().length()<1000) {
            temp = f1;
            f1 = f2;
            f2 = temp.add(f1);
            i++;
        }

        System.out.println(i);
    }
}