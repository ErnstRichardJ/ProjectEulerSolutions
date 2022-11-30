#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

bool isPrime(int n) {
    if (n == 2) return true;
    if (!n%2) return false;
    for (int i = 3; i*i <= n; i+=2) {
        if (n%i==0) return false;
    }
    return true;
}

int pow(int a, int b) {
    if (b == 0) return 1;
    return a * pow(a,b-1);
}

unordered_set<int> primes;

bool isCircular (int p) {
    int len = to_string(p).length();
    int r = p;

    for (int i = 1; i < len; i++) {
        r = (r/10) + (r%10)*pow(10,len-1);
        if (!primes.count(r)) return false;
    }
    return true;
}

int main() {
    primes.insert(2);
    int count = 0;
    for (int i = 3; i < 1000000; i+=2) {
        if (isPrime(i)) primes.insert(i);
    }
    
    for (int p : primes) {
        if (isCircular(p)) {
            count++;
        }
    }
    cout << count << endl;
}