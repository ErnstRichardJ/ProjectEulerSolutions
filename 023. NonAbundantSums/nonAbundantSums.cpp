#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int addDivisors(int n) {
    int sum = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n%i==0) {
            // Square roots dont come in pairs like every other divisor
            if (i*i == n) sum += i; 
            else sum += i + n/i;
        }
    }
    return sum-n;
}

int main() {
    vector<int> abundants;

    for (int i = 12; i < 28124; i++) {
        int d = addDivisors(i);
        if (d > i) abundants.push_back(i);
    }
    int sum = 0;

    bool abundantSums[28124] = {false};

    for (int i : abundants) {
        for (int j : abundants) {
            if (i+j < 28124) abundantSums[i+j] = true;
            else break;
        }
    }

    for (int i = 1; i < 28124; i++) {
        if (!abundantSums[i]) sum += i;
    }

    cout << sum << endl;
}