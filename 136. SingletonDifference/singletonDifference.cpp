#include <iostream>
#include <vector>

using namespace std;

int main() {
    int total = 0;

    vector<int> solutions(50000000,0);

    for (int x = 1; x < 50000000; x++) {
        for (int y = 1; x*y < 50000000; y++) {
            if ((y+x)%4==0 && y+x < 4*x) solutions[x*y]++;
        }
    }

    for (int s : solutions) {
        if (s == 1) total++;
    }
    cout << total << endl;
}