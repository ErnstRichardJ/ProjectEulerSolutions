#include <iostream>
#include <stdio.h>
bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n = 1;
    int x = 1;
    while (n <= 10001) {
        x++;
        if (isPrime(x)) {
            n++;
        }
        
    }
    std::cout << x;
}