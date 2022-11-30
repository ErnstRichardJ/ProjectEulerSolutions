#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int alphabetValue(string s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += s[i]-64;
    }
    return sum;
}

int main() {
    ifstream file;

    file.open("names.txt");

    string s;
    vector<string> names;
    int i = 0;

    while (file >> s) {
        names.push_back(s);
    }

    sort(names.begin(),names.end());

    int size = names.size();
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += (i+1)*alphabetValue(names[i]);
    }
    cout << sum << endl;
    file.close();
}