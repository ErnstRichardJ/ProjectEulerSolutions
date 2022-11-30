#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

static set<int> primes;

struct RadPair {
    int n, rad;

    RadPair(int n, int rad) : n(n), rad(rad) {}

    inline bool operator() (const RadPair &pair1, const RadPair &pair2) {
        if (pair1.rad < pair2.rad) return true;
        if (pair1.rad > pair2.rad) return false;

        if (pair1.n < pair2.n) return true;

        return false;
    }
};

struct compare {
    inline bool operator() (const RadPair &pair1, const RadPair &pair2) {
        if (pair1.rad < pair2.rad) return true;
        if (pair1.rad > pair2.rad) return false;

        if (pair1.n < pair2.n) return true;

        return false;
    }
};

bool isPrime(int p) {
    if (p == 1) return false;
    if (!(p%2)) return false;

    for (int i = 3; i * i <= p; i+=2) {
        if (!(p % i)) return false;
    }

    return true;
}

int nextPrime(int p) {
    if (p == 2) return 3;
    do {
        if (p%6 == 1) p += 4;
        else p += 2;
    } while (!isPrime(p));
    return p;
}

int rad(int n) {
    int product = 1;

    for (int p : primes) {
        if (p > n) break;
        if (!(n%p)) product *= p;
    }

    return product;
}

#define limit 100000

int main() {
    int p = 2;
    while (p < limit) {
        primes.insert(p);
        p = nextPrime(p);
    }

    vector<RadPair> pairs;

    for (int i = 1; i <= limit; i++) {
        int r = rad(i);
        pairs.push_back(RadPair(i,r));
    }

    sort(pairs.begin(), pairs.end(), compare());

    cout << pairs[10000-1].n << endl;
}