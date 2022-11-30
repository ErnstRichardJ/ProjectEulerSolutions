#include <iostream>

using namespace std;


/**
 * (a-1)^n+(a+1)^n mod n can be calculated in constant time using the binomial expansion.
 * (a+b)^n makes pascal's triangle, but (a+b)^n mod a^2 will only compute the right 2 diagonals of pascal's triangle.
 * So, (a+b)^n mod a^2 = na(b^(n-1))+b^n mod a^2
 * 
 * Therefore (a-1)^n mod a^2 = na((-1)^(n-1)))+(-1)^n mod a^2
 * and       (a+1)^n mod a^2 = na(1^(n-1)) + 1 mod a^2
 * 
 * So, (a-1)^n + (a+1)^n mod a^2 =
 * 2 when n = 0 mod 2 and,
 * 2na mod a^2 when n = 1 mod 2
 * 
 * Therefore 2na = r mod a^2.
 * Since a^2 = 0 mod a^2, 2n < a.
 * So the first largest n = (a-1)/2
 * and r = 2a((a-1)/2)
 * 
 * Note that r != a(a-1) since a and a-1 do not have the same parity
 */
int main() {
    int sum = 0;
    for (int a = 3; a <= 1000; a++) {
        sum += 2*a*((a-1)/2);
    }
    cout << sum << endl;
}