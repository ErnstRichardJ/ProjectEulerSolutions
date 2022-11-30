#include <iostream>
#include <tgmath.h>
#include <cstdint>

using namespace std;

#define tiles 1000000

int main() {
    uint64_t count = 0;
    for (uint64_t i = 3; i <= tiles/4+1; i++) { 
        if (i*i <= tiles) {
            count += i/2 - 1 + i%2;
        } else {
            double n = ceil(sqrt(i*i-tiles));
            for (uint64_t j = n; j < i; j++) {
                if (j%2 != i%2) continue;
                if (i*i-j*j <= tiles) count++;
            }
        }
    }
    cout << count;
}