#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int squareDigits(int n) {
    int total = 0;

    while (n) {
        total += (n%10) * (n%10);
        n /= 10;
    }

    return total;
}

int main() {
    steady_clock::time_point begin, end;
    int count;

    begin = steady_clock::now();

    count = 0;
    bool cache[568] = {false};

    for (int i = 1; i < 568; i++) {
        int x = i;
        while (x != 1 && x != 89) {
            x = squareDigits(x);
        }

        if (x == 89) {
            count++;
            cache[i] = true;
        }
    }

    for (int i = 567; i < 10000000; i++) {
        if (cache[squareDigits(i)]) count++;
    }

    cout << count << endl;

    end = steady_clock::now();

    cout << "Time difference = " << duration_cast<milliseconds>(end - begin).count() << "[ms]" << endl;
}