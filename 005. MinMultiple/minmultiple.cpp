#include <iostream>
#include <stdio.h>

long long lcm(long long p, long long q) {
    long long a = p;
    long long b = q;

    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return (p*q) / a;
}

int main() {
    long long x = 1;
    for (long long i = 2; i <= 20; i++) {
        x = lcm(i,x);
    }
    std::cout << x;
}