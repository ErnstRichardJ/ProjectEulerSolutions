#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int maxCount = 0;
    int maxP = 0;

    for (int p = 12; p <= 1000; p++) {
        int count = 0;
        for (int a = 3; a <= p/3; a++) {
            for (int b = a; b <= p/2; b++) {
                if (a+b+sqrt(a*a+b*b)==p) {
                    count++;
                }
            }
        }
        if (count > maxCount) {
            maxCount = count;
            maxP = p;
            cout << p << ": " << count << endl;
        }
    }
    cout << maxP << ": " << maxCount << endl;
}