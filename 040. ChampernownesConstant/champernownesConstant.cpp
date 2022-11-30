#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;

    int i = 1;
    while (s.length() < 1000000) {
        s.append(to_string(i++));
    }
    
    for (int i = 1; i <= 1000000; i*=10) {
        cout << s[i-1]-48 << " ";
    }
    
    cout << endl;
}