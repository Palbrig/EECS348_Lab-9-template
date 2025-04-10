#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "matrix.hpp"
using namespace std;

int main(int argc, char *argv[]) {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    size_t N;
    int type_flag;

    infile >> N >> type_flag;

    if (type_flag != 0) {
        cerr << "Only integer matrices (type 0) are supported in this version.\n";
        return 1;
    }

    vector<vector<int>> vec1(N, vector<int>(N));
    vector<vector<int>> vec2(N, vector<int>(N));

    for (size_t i = 0; i < N; i++){
        for (size_t j = 0; j < N; j++)
        {
            infile >> vec1[i][j];
        }
    }

    for (size_t i = 0; i < N; i++){
        for (size_t j = 0; j < N; j++)
        {
            infile >> vec2[i][j];
        }
    }

    infile.close();

    Matrix matrix1(vec1);
    Matrix matrix2(vec2);

    cout << "\nMatrix 1:\n";
    matrix1.print_matrix();
    cout << "\nMatrix 2:\n";
    matrix2.print_matrix();

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();
}
