#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool isTriangular(int n) {
    int i = 1;

    while (n > 0) {
        n -= i;
        i++;
    }

    return n == 0;
}

int alphabetValue(string s) {
    int n = 0;
    for (char c : s) {
        n += c-64;
    }
    return n;
}

int main() {
    vector<string> words;
    ifstream file;

    file.open("p042_words.txt");

    string s;
    while (file >> s) {
        words.push_back(s);
    }

    int total = 0;

    for (string s : words) {
        if (isTriangular(alphabetValue(s))) total++;
    }
    cout << total << endl;
}