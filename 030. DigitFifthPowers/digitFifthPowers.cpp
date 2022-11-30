#include <iostream>
#include <vector>

using namespace std;

vector<int> digits(int n) {
    vector<int> v;
    while (n > 0) {
        v.push_back(n%10);
        n/=10;
    }
    return v;
}

int sumFifths(vector<int> digits) {
    int sum = 0;
    for (int n : digits) {
        sum += n*n*n*n*n;
    }
    return sum;
}

int main() {
    int sum = 0;
    for (int i = 2; i < 1000000; i++) {
        if (i == sumFifths(digits(i))) {
            sum += i;
        }
    }
    cout << sum << endl;
}