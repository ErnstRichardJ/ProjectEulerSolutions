#include <iostream>
int main() {
    int sum_square = 0;
    int square_sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum_square += i * i;
        square_sum += i;
    }
    square_sum *= square_sum;

    std::cout << square_sum - sum_square;
}