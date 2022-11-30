#include <iostream>
#include <chrono>
#include <unordered_map>

using namespace std;

int reverse(int n) {
    int reverse = 0;
    while (n) {
        reverse = 10*reverse + n%10;
        n /= 10;
    }
    return reverse;
}

bool isOddDigits(int n) {
    do {
        if(!(n%2)) return false;
        n/=10;
    }while(n);
    return true;
}

int main() {
    int count = 0;

    for (int i = 0; i < 1000000000; i++) {
        if ((i%10)&&isOddDigits(i+reverse(i))) count++;
    }

    cout << count << endl;
}