#include <iostream>

int main() {
    const int months[12] = {3,0,3,2,3,2,3,3,2,3,2,3};

    int day = 1; // monday == 0 mod 7 sunday == 6 mod 7
    int sundays = 0;

    for (int year = 1901; year < 2001; year++) {
        for (int month = 0; month < 12; month++) {
            if (year % 4==0 && month == 1) day++;
            day = (day + months[month]) % 7;
            if (day == 6) sundays++;
        }
    }

    std::cout << sundays;
}