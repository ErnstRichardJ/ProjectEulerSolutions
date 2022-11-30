#include <string>
#include <iostream>

using namespace std;

bool isPalindrome(int x) {
    string s = to_string(x);
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != s[s.length()-1-i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int biggest = 0;

    for (int i = 100; i <= 999; i++) {
        for (int j = 100; j <= 999; j++) {
            int x = i * j;
            if (isPalindrome(x) && x > biggest) biggest = x;
        }
    }
    cout << biggest << endl;
}