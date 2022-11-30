#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

bool isPrime(uint64_t x) {
    if (x == 1) return false;

    for (uint64_t i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

uint64_t nextPrime(uint64_t p) {
    if (p == 2) return 3;
    do {
        p += 2;
    } while (!isPrime(p));
    return p;
}

uint64_t reverse(uint64_t n) {
    uint64_t reverse = 0;
    while (n) {
        reverse = 10*reverse + n%10;
        n /= 10;
    }
    return reverse;
}

int main() {
    int count = 0;
    uint64_t sum = 0;
    uint64_t p = 2;

    while (count < 50) {
        uint64_t q = reverse(p*p);
        if (p*p != q && !fmod(sqrt(q),1) && isPrime(sqrt(q))) {
            count++;
            sum += p*p;
        }
        p = nextPrime(p);
    }
    cout << sum << endl;
}