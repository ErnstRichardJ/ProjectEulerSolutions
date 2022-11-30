#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace chrono;

double quadratic(double a, double b, double c) {
    return (-b + sqrt(b*b-4*a*c))/(2*a);
}

bool isFigurate(int n, int figurate) {
    double a, b;
    switch(figurate) {
        case 3: a = 0.5; b = 0.5; break;
        case 4: a = 1; b = 0; break;
        case 5: a = 1.5; b = -0.5; break;
        case 6: a = 2; b = -1; break;
        case 7: a = 2.5; b = -1.5; break;
        case 8: a = 3; b = -2; break;
    }
    return fmod(quadratic(a,b,-n),1) == 0;
}

bool isFigurate(int n) {
    for (int i = 3; i <= 8; i++) {
        if (isFigurate(n,i)) 
            return true;
    }
    return false;
}

bool isFigurateList(int numbers[6]) {
    //bool figurateFound[6] = {false,false,false,false,false,false};

    char figurateFound = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (isFigurate(numbers[i],j+3)) {
                if (j != 0 && j != 3 && (figurateFound & (1<<j))) return false;
                figurateFound |= 1<<j;
            }
        }
    }
    
    return figurateFound == 0x3f;
}

int main() {
    for (int a = 10; a < 100; a++) {
        for (int b = 10; b < 100; b++) {
            int first = 100*a+b;

            if (!isFigurate(first)) 
                continue;

            for (int c = 10; c < 100; c++) {
                int second = 100*b+c;

                if (!isFigurate(second)) 
                    continue;

                for (int d = 10; d < 100; d++) {
                    int third = 100*c+d;

                    if (!isFigurate(third)) 
                        continue;

                    for (int e = 10; e < 100; e++) {
                        int fourth = 100*d+e;

                        if (!isFigurate(fourth)) 
                            continue;

                        for (int f = 10; f < 100; f++) {
                            int fifth = 100*e+f;

                            if (!isFigurate(fifth)) 
                                continue;

                            int sixth = 100*f+a;
                            if (!isFigurate(sixth)) 
                                continue;

                            int numbers[6] = {first,second,third,fourth,fifth,sixth};
                            int sum = 0;

                            if (isFigurateList(numbers)) {
                                for (int n : numbers) {
                                    sum += n;
                                }
                                cout << sum << endl;
                                exit(0);
                            }
                        }
                    }
                }
            }
        }
    }
}