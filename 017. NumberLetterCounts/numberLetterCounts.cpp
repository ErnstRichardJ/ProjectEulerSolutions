#include <iostream>

int main() {
    int oneToNine = 36;

    int tenToNineteen = 70;
    
    int twentyToNinetynine = 8*oneToNine + 10*(6+6+5+5+5+7+6+6);

    int oneToNinetynine = oneToNine + tenToNineteen + twentyToNinetynine;

    int hundreds = 9*(99*(7+3) + 7); // number of hundred(and)s (x01-x99 are hundred ands, x00 is just hundred )

    int thousand = 11;
    
    int x = 10 * oneToNinetynine + hundreds + 100 * oneToNine + thousand;

    std::cout << x << std::endl;
}