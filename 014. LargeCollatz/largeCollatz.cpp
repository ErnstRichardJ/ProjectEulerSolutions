#include <iostream>
int main() {
    int longest = 0;
    int longest_length;
    for (int i = 1; i < 1000000; i++) {
        long long n = i;
        int length = 1;
        while (n != 1) {
            length++;
            if (n%2==0)
                n = n/2;
            else
                n = 3*n + 1;
        }
        if (length > longest_length) {
            longest = i;
            longest_length = length;
        }
    }
    std::cout << longest;
}