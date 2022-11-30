#include <iostream>
#include <string>
#include <bitset>

using namespace std;

string binaryString(unsigned int n) {
    string binary = "";
    while (n > 0) {
        if (n%2) binary = "1" + binary;
        else binary = "0" + binary;
        n/=2;
    }
    return binary;
}

bool isPalindrome(string s) {
    for (int i = 0; i < s.length()/2; i++) {
        if (s[i] != s[s.length()-1-i]) return false;
    }
    return true;
}

int main() {
    int sum = 0;
    for (int i = 1; i < 1000000; i++) {
        if (isPalindrome(to_string(i)) && isPalindrome(binaryString(i))) sum += i;
    }
    cout << sum << endl;
}