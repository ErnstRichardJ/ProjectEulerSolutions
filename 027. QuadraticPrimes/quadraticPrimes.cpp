#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n == 2) return true;
    if (n < 0 || !n%2) return false;
    for (int i = 3; i*i <= n; i+=2) {
        if (n%i==0) return false;
    }
    return true;
}

int main() {
    int maxN = 0;
    int product = 0;
    for (int a = -999; a < 1000; a++) {
        for (int b = -1000; b <= 1000; b++) {

            int n = 0;
            while (isPrime(n*n+a*n+b)) {
                n++;
            }
            if (n > maxN) {
                maxN = n;
                product = a*b;
            }
        }
    }
    cout << maxN << " " << product;
}