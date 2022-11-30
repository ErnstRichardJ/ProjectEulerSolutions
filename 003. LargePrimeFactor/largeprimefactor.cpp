#include <iostream>
#include <math.h>

int main() {
    long long x = 600851475143;

    for (long long i = 2; i * i < x; i++) {
        while (x % i == 0) x /= i;
    }

    std::cout << x << std::endl;
}