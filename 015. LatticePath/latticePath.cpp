#include <iostream>

int main() {
    #define size 5

    long long arr[size + 1][size + 1] = {0};
    
    arr[size][size] = 1;

    for (int i = size; i >= 0; i--) {
        for (int j = size; j >= 0; j--) {
            if (i == size || j == size) arr[i][j] = 1;
            else arr[i][j] = arr[i+1][j] + arr[i][j+1];
        }
    }

    std::cout << arr[0][0] << std::endl;
}