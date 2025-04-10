#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "matrix.hpp"
using namespace std;

void pauseCommandLine();
void problem1(Matrix, Matrix);
void problem2(Matrix, Matrix);
void problem3(Matrix, Matrix);
void problem4(Matrix);
void problem5(Matrix&, int, int);
void problem6(Matrix&, int, int);
void problem7(Matrix&, int, int, int);

int main(int argc, char *argv[]) {
    string filename = "test.txt";
    // cout << "Enter filename: ";
    // cin >> filename;

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
            string token;
            infile >> token;
            vec1[i][j] = stoi(token, nullptr, 10);
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

    problem1(matrix1, matrix2);
    problem2(matrix1, matrix2);
    problem3(matrix1, matrix2);
    problem4(matrix1);
    problem4(matrix2);
    problem5(matrix1, 1, 2);
    problem6(matrix1, 1, 2);
    problem7(matrix1, 0, 0, 100);

    pauseCommandLine();
}

void pauseCommandLine(){
    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();
}

void problem1(Matrix m1, Matrix m2){
    cout << "\nMatrix 1:\n";
    m1.print_matrix();
    cout << "\nMatrix 2:\n";
    m2.print_matrix();
}

void problem2(Matrix m1, Matrix m2){
    cout << "\nAdding Matrix 1 to Matrix 2:\n";
    (m1 + m2).print_matrix();
}

void problem3(Matrix m1, Matrix m2){
    cout << "\nMultiplying Matrix 1 to Matrix 2:\n";
    (m1 * m2).print_matrix();
}

void problem4(Matrix m1){
    cout << "\nAdding Major Diagonal Elements: " << m1.sum_diagonal_major() << "\n";
    cout << "\nAdding Minor Diagonal Elements: " << m1.sum_diagonal_minor() << "\n";
}

void problem5(Matrix& m1, int i, int j){
    cout << "Swapping row " << i << " with row " << j << ":\n";
    m1.swap_rows(i, j);
    m1.print_matrix();
}

void problem6(Matrix& m1, int i, int j){
    cout << "Swapping col " << i << " with col " << j << ":\n";
    m1.swap_cols(i, j);
    m1.print_matrix();
}

void problem7(Matrix& m1, int row, int col, int val){
    cout << "Changing row " << row << " col " 
         << col << " that is value " << m1.get_value(row, col) << 
         " with value " << val << "\n";
    m1.set_value(row, col, val);
    m1.print_matrix();
}