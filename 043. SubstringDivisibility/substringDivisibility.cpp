#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

long long undigits(vector<long long> d) {
    long long n = d[0];
    for (long long i = 1; i < d.size(); i++) {
        n = 10*n + d[i];
    }
    return n;
}

int main() {
    vector<long long> v {1,0,2,3,4,5,6,7,8,9};
    long long sum = 0;
    do { 
        char flags = 0;

        flags |= (v[3] % 2 == 0);
        flags |= ((v[2] + v[3] + v[4]) % 3 == 0) << 1;
        flags |= (v[5] % 5 == 0) << 2;
        flags |= ((100*v[4] + 10*v[5] + v[6]) % 7 == 0) << 3;
        flags |= ((100*v[5] + 10*v[6] + v[7]) % 11 == 0) << 4;
        flags |= ((100*v[6] + 10*v[7] + v[8]) % 13 == 0) << 5;
        flags |= ((100*v[7] + 10*v[8] + v[9]) % 17 == 0) << 6;

        if (flags == 0x7f) {
            sum += undigits(v);
        }
    } while (next_permutation(v.begin(),v.end()));

    cout << sum << endl;
}