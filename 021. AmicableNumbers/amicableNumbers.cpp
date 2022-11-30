#include <iostream>
#include <unordered_map>
#include <math.h>

using namespace std;

int d(int n) {
    int sum = 0;
    for (int i = 1; i < sqrt(n); i++) {
        if (n%i==0) {
            // Square roots dont come in pairs like every other divisor
            if (i*i == n) sum += i; 
            else sum += i + n/i;
        }
    }
    return sum-n;
}

#define size 10000

int main() {
    unordered_map<long, long> umap; // hash map of d(n) to save computation time

    for (long i = 1; i < size; i++) {
        umap[i] = d(i);
    }

    long sum = 0;

    for (long i = 1; i < size; i++) {
        long n = umap.find(i)->second;
        // i is amicable iff the hash map has key d(i), d(d(i)) == i, and i != d(i)
        if (umap.find(n) != umap.end()) {
            if (i == umap.find(n)->second && i != n) {
                sum += i;
            }
        }
    }

    cout << sum << endl;

    sum = 0;
    
    // Faster implementation at small sizes, but grows faster. Both in O(n sqrt(n)) but this algorithm calls d(n) twice
    // At size = 10,000 this is ~2ms faster, but at size = 1,000,000 this is ~1.5s slower
    // But this algorithm uses substantially less memory
    for (long a = 1; a < size; a++) {
        long b = d(a);

        if (b > size) continue;

        if (a != b && d(b) == a) sum += a;
    }

    cout << sum << endl;
}