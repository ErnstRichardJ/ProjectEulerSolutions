#include <iostream>

int count_factors(long long x) {
    int count = 0;
    for (long long i = 1; i * i < x; i++) {
        if (x%i==0) {
            count++;
        }
    }
    return count * 2;
}

int main() {
    long long x = 1;
    long long increment = 1;
    while(true) {
        if (count_factors(x) >= 500) break;

        increment++;
        x += increment;
    }
    std::cout << x << " " << count_factors(49);
}