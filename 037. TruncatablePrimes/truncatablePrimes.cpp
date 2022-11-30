#include <iostream>
#include <string>

using namespace std;

bool isPrime(int x) {
    if (x == 1) return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

bool isTruncatablePrime(int x) {
    int left = x, right = x;

    while (left > 0 && right > 0) {
        if (!isPrime(left) || !isPrime(right)) return false;

        right /= 10;

        try {
            left = stoi(to_string(left).substr(1));
        } catch (exception) {
            left = -1;
        }
    }

    return true;
}

int main() {
    int sum = 0;
    int total = 0;
    int i = 23;

    while (total < 11) {
        if (isTruncatablePrime(i)) {
            sum += i;
            total++;
            cout << i << endl;
        }
        i += 2;
    }

    cout << sum << endl;
}