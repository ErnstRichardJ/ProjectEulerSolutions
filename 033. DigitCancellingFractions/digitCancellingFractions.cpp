#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a == 0 || b == 0)
        return 0;
    else if (a == b)
        return a;
    else if (a > b)
        return gcd(a-b, b);
    else 
        return gcd(a, b-a);
}

int main() {
    int productNum = 1;
    int productDen = 1;
    for (int i = 10; i < 100; i++) {
        for (int j = i+1; j < 100; j++) {
            if (i % 10 == j / 10) {
                if (j*(i/10) == i*(j%10)) {
                    productNum *= i;
                    productDen *= j;
                }
            }
        }
    }
    cout << productNum << "/" << productDen << endl;
    cout << productDen/gcd(productNum, productDen) << endl;
}