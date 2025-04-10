/*
Author: Parker Albright
Description: matrix.hpp defines a class matrix and includes functionality
to edit and change the matrix.
*/

#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>
#include <iostream>
#include <iomanip>


// all of your function definitions should be in this file now
// Defines place holders for all matrix functionality.
class Matrix {
private: 
    std::size_t size;
    std::vector<std::vector<int>> data;
public:
    Matrix(std::size_t N);
    Matrix(std::vector<std::vector<int>> nums);
    // Chat GPT offered the friend type here
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;

    // Defined here for template finicky
    template <typename T>
    void set_value(std::size_t i, std::size_t j, T n){
        data[i][j] = n; 
    }

    int get_value(std::size_t i, std::size_t j) const;
    int get_size() const;
    int sum_diagonal_major() const;
    int sum_diagonal_minor() const;
    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);
    void print_matrix() const;
};

// Matrix constructors
Matrix::Matrix(std::size_t N){
    size = N;
    data.resize(size);

    for (std::size_t i = 0; i < size; i++) {
        data[i].resize(size);
        for (std::size_t j = 0; j < size; j++)
        {
            data[i][j] = 0;
        }
        
    }
    
}
Matrix::Matrix(std::vector<std::vector<int>> nums){
    size = nums.size();
    data.resize(size);

    for (size_t i = 0; i < size; i++)
    {
        data[i].resize(size);
        for (size_t j = 0; j < size; j++)
        {
            data[i][j] = nums[i][j];
        }
        
    }
    
}

// Replaces << operator to output below when called in cout
std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    os << "Matrix of type int: ";
    return os;
}

// Replaces + operator to add matrices together
Matrix Matrix::operator+(const Matrix &rhs) const {
    Matrix result(size);

    for (std::size_t i = 0; i < size; i++) {
        for (std::size_t j = 0; j < size; j++) { 
            result.data[i][j] = data[i][j] + rhs.data[i][j];
        }
    }
    return result;
}

// Replaces * operator to multiply matrices together
Matrix Matrix::operator*(const Matrix &rhs) const {
    Matrix result(size);

    for (std::size_t i = 0; i < size; i++) {
        for (std::size_t j = 0; j < size; j++) {
            result.data[i][j] = 0;
            for (std::size_t k = 0; k < size; k++){
                result.data[i][j] += data[i][k] * rhs.data[k][j];
            }
        }
    }
    return result;
}

int Matrix::get_value(std::size_t i, std::size_t j) const { return data[i][j]; }

int Matrix::get_size() const { return data.size(); }

int Matrix::sum_diagonal_major() const { 
    int result = 0;

    for (std::size_t k = 0; k < size; k++){
        result += data[k][k];
    }

    return result;
}

int Matrix::sum_diagonal_minor() const {
    int result = 0;

    for (std::size_t i = 0; i < size; ++i) {
        result += data[i][size - 1 - i];
    }

    return result;
}

void Matrix::swap_rows(std::size_t r1, std::size_t r2){
    if(r1 < size && r2 < size)
    {
        std::vector<int> storedVector = data[r1];
        data[r1] = data[r2];
        data[r2] = storedVector;
    }
}

void Matrix::swap_cols(std::size_t c1, std::size_t c2){
    std::vector<std::vector<int>> storedVector;
    storedVector.resize(size);

    if(c1 < size && c2 < size)
    {
        for (size_t i = 0; i < size; i++)
        {
            storedVector[i].resize(size);
        }

        for (size_t i = 0; i < size; i++)
        {
            storedVector[i][c1] = data[i][c1];
        }

        for (size_t i = 0; i < size; i++)
        {
            data[i][c1] = data[i][c2];
        }

        for (size_t i = 0; i < size; i++)
        {
            data[i][c2] = storedVector[i][c1];
        }
    }
}
void Matrix::print_matrix() const{
    for (std::size_t i = 0; i < size; i++) {
        for (std::size_t j = 0; j < size; j++){
            std::cout << std::setw(5) << data[i][j];
        }
        std::cout << '\n';
    }
}

#endif // __MATRIX_HPP__
