#include <iostream>

using namespace std;

#define e10 10000000000L

bool isPrime(int x) {
    if (x == 1) return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int nextPrime(int p) {
    if (p == 2) return 3;
    do {
        p += 2;
    } while (!isPrime(p));
    return p;
}


/**
 * Uses the same concept from p120 but is simpler since a and n are dependent on each other. 
 */
int main() {
    int n = 1;
    unsigned long long p = 2; // 

    while(true) {
        if (((2*n*p)%(p*p)) > e10) {
            cout << n << endl;
            cout << p;
            break;
        }
        n += 2;
        p = nextPrime(nextPrime(p)); // when n == 0 mod 2, remainder is always 2
    }
}