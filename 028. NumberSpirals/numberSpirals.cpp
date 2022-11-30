#include <iostream>
using namespace std;
int main() {
    int sum = 1;
    for (int i = 3; i <= 1001; i+=2) {
        // Sum of a ring size n = n^2 + n^2 - (n-1) + n^2 - 2(n-1) + n^2 - 3(n-1)
        // Which reduces to 4n^2 - 6n + 6
        sum += 4*i*i - 6*i + 6;
    }
    cout << sum << endl;
}