#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> digits(int n) {
    vector<int> v;
    while (n > 0) {
        v.insert(v.begin(), n%10);
        n /= 10;
    }
    sort(v.begin(),v.end());
    return v;
}

int main() {
    int i = 1;
    while (true) {
        vector<int> one   = digits(i);
        vector<int> two   = digits(2*i);
        vector<int> three = digits(3*i);
        vector<int> four  = digits(4*i);
        vector<int> five  = digits(5*i);
        vector<int> six   = digits(6*i);
        if(one == two && one == three && one == four && one == five && one == six) {
            cout << i << endl;
            break;
        }
        i++;
    } 
}