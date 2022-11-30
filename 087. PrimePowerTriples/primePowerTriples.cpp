#include <iostream>
#include <unordered_set>

using namespace std;

bool isPrime(int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n%i==0) return false;
    }
    return true;
}

int nextPrime(int n) {
    if (n == 2) return 3;
    do {
        n += 2; 
    } while (!isPrime(n));
    return n;
}

int main() {
    int a = 2, b = 2, c = 2, count = 0;

    unordered_set<int> set;

    do {   
        do {
            do {
                //cout << a << "^2 + " << b << "^3 + " << c << "^4" << endl;
                int n = a*a + b*b*b + c*c*c*c;
                if (!set.count(n)) {
                    count++;
                    set.insert(n);
                }
                c = nextPrime(c);
            } while (a*a + b*b*b + c*c*c*c < 50000000);
            b = nextPrime(b);
            c = 2;
        } while (a*a + b*b*b + c*c*c*c < 50000000);
        a = nextPrime(a);
        b = 2;
    } while (a*a + b*b*b + c*c*c*c < 50000000);

    cout << count;
}