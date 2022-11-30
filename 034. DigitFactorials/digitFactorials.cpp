#include <iostream>
#include <vector>

using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return n*factorial(n-1);
}

vector<int> digits(int n) {
    vector<int> v;
    while (n > 0) {
        v.push_back(n%10);
        n/=10;
    }
    return v;
}

int sumFactDigits(int n) {
    int sum = 0;
    for (int d : digits(n)) sum += factorial(d);
    return sum;
}

int main() {
    int sum = 0;
    for (int i = 10; i < 1000000; i++) {
        if (i == sumFactDigits(i)) {
            sum += i;
        }
    }
    cout << sum << endl;
}