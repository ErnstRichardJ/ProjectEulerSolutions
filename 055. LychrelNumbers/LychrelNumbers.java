import java.math.BigInteger;
import java.lang.StringBuilder;

public class LychrelNumbers {

    public static void main(String[] args) {
        int count = 0;

        for (int i = 1; i < 10000; i++) {
            if (isLychrel(i)) count++;
        }

        System.out.println(count);
    }

    public static boolean isLychrel(int n) {
        BigInteger x = BigInteger.valueOf(n);

        for (int j = 0; j < 50; j++) {
            x = x.add(reverse(x));
            if (isPalindrome(x)) {
                return false;
            }
        }    

        return true;
    }

    public static boolean isPalindrome(BigInteger n) {
        StringBuilder sb = new StringBuilder(n.toString());
        return n.toString().equals(sb.reverse().toString());
    }

    public static int reverse(int n) {
        StringBuilder sb = new StringBuilder(Integer.toString(n));
        return Integer.valueOf(sb.reverse().toString());
    }

    public static BigInteger reverse(BigInteger n) {
        StringBuilder sb = new StringBuilder(n.toString());
        return new BigInteger(sb.reverse().toString());
    }
}