#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

#define SIZE 80

int main() {
    ifstream file;

    file.open("p081_matrix.txt");

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

    for (int x = SIZE - 1; x >= 0; x--) {
        for (int y = SIZE - 1; y >= 0; y--) {
            if (x == SIZE - 1 && y == SIZE - 1) continue;

            if (x == SIZE - 1) matrix[x][y] += matrix[x][y+1];
            else if (y == SIZE - 1) matrix[x][y] += matrix[x+1][y];
            else matrix[x][y] += min(matrix[x][y+1], matrix[x+1][y]);
        }
    }

    cout << matrix[0][0] << endl;
}