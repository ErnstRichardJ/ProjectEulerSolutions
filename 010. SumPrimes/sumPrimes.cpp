#include <iostream>
using namespace std;

bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    long long sum = 0;
    for (int i = 2; i < 2000000; i++) {
        if (isPrime(i)) sum += i;
    }
    cout << sum;
}