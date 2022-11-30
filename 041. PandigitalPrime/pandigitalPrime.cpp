#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int x) {
    if (x == 1) return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

vector<int> digits(int n) {
    vector<int> v;
    while (n > 0) {
        v.insert(v.begin(), n%10);
        n /= 10;
    }
    return v;
}

int undigits(vector<int> d) {
    int n = d[0];
    for (int i = 1; i < d.size(); i++) {
        n = 10*n + d[i];
    }
    return n;
}

vector<int> permute(int n) {
    vector<int> v = digits(n);
    vector<int> p;
    do {
        p.push_back(undigits(v));
    } while (next_permutation(v.begin(),v.end()));
    return p;
}

int main() {
    vector<int> permutations = permute(1234567);
    int i = permutations.size()-1;
    while (!isPrime(permutations[i])) {i--;}
    cout << permutations[i];
}