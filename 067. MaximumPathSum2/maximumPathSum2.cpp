#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream file;

    file.open("p067_triangle.txt");

    vector<vector<int>> matrix;

    string line, value;

    while (file >> line) {
        vector<int> row;
        stringstream s (line);
        while (getline(s, value, ',')) {
            row.push_back(stoi(value));
        }
        matrix.push_back(row);
    }

    for (int i = matrix.size()-2; i >= 0; i--) {
        for (int j = 0; j < 1+i; j++) {
            int left = matrix[i+1][j];
            int right = matrix[i+1][j+1];

            matrix[i][j] += left > right ? left : right;
        }
    }
    cout << matrix[0][0];
}