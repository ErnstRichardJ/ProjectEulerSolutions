#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool isPalindrome(string s) {
    for (int i = 0; i < s.length()/2; i++) {
        if (s[i] != s[s.length()-1-i]) return false;
    }
    return true;
}

int main() {
    long long sums = 0;

    unordered_set<int> set;

    for (int i = 1; i <= 10000; i++) {
        int j = i+1;
        int sum = i*i + j*j;

        while (sum < 100000000) {
            if (set.find(sum) == set.end() && isPalindrome(to_string(sum))) {
                sums += sum;
                set.insert(sum);
            }
            j++;
            sum += j*j;
        }
    }
    cout << sums << endl;
}