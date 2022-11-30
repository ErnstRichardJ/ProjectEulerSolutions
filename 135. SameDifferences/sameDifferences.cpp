#include <iostream>
#include <vector>

using namespace std;

/**
 * since x,y,z are in an arithmetic sequence, the problem can be rewritten:
 * (a+k)^2-a^2-(a-k)^2 = n where a>k.
 * 
 * This simplifies to:
 * a(4k-a)=n
 * 
 * Letting x = a and y = 4k-a, we can iterate over the products less than 1000000.
 * since y=4k-a, k=(y+a)/4=(y+x)/r, so y+x must be congruent to 0 mod 4.
 * 
 * Additionally since a>k, x>(y+x)/4. So 4x > y + x.
 * 
 * Note that 4k-a must also be positive but clearly x+y>x when x and y > 0.
 * 
 * So the solutions for any n is the number of products xy that satisfy these properties.
 */
int main() {
    int total = 0;

    vector<int> solutions(1000000,0);

    for (int x = 1; x < 1000000; x++) {
        for (int y = 1; x*y < 1000000; y++) {
            if ((y+x)%4==0 && y+x < 4*x) solutions[x*y]++;
        }
    }

    for (int s : solutions) {
        if (s == 10) total++;
    }
    cout << total << endl;
}