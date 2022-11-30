#include <iostream>

using namespace std;

bool isPrime(int x) {
    if (x == 1) return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n = 35;

    while (true) {
        if (!isPrime(n)) {
            bool possible = false;
            for (int i = 1; 2*i*i < n; i++) {
                if (isPrime(n-2*i*i)) {
                    possible = true;
                    break;
                }
            }   
            if (possible == false) {
                cout << n << endl;
                break;
            }
        }  
        n += 2;
    }
}