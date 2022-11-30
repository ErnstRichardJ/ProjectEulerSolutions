#include <iostream>
#include <cstdint>
#include <cmath>
#include <set>

using namespace std;

#define e12 1000000000000ULL

uint64_t gcd(uint64_t a, uint64_t b) {
    if (a == 0 || b == 0)
        return 0;
    else if (a == b)
        return a;
    else if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main() {
    uint64_t sum = 0;

    set<uint64_t> set;

    for (uint64_t a = 2; a < 10000; a++) {
        for (uint64_t b = 1; b < a; b++) {
            if (a*a*a*b*b+b >= e12) break;
            if (gcd(a,b) != 1) continue;
            uint64_t x = 1;
            while (true) {
                uint64_t n = x*b*b+x*x*a*a*a*b;
                if (n >= e12) break;
                // sqrt(n) is an integer and n hasn't been found
                if (fmod(sqrt(n),1) == 0 && set.find(n) == set.end()) {
                    set.insert(n);
                    sum += n;
                }
                x++;
            }
        }
    }

    cout << sum << endl;
}