#include <iostream>
#include <cmath>

using namespace std;

// quadratic formula for 3x^2/2-x/2-n=0
// a real number is congruent to 0 mod 1 iff it is an integer
bool isPentagonal(int n) {
    return fmod((0.5 + sqrt(0.25+6.0*n))/(3),1) == 0;
}

int main() {
    int hex = 40755;
    int delta = 573;

    do {
        hex += delta;
        delta += 4;
    } while (!isPentagonal(hex));
    cout << hex << endl;
}