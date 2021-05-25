#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <iostream>

class Matrix {
public:
    Matrix(unsigned int rows, unsigned int columns);
    Matrix(unsigned int rows, unsigned int columns, std::vector<std::vector<double>> const & coef);
    double operator()(unsigned int r, unsigned int c) const;
    unsigned int getRows() const;
    unsigned int getColumns() const;
    double det(Matrix const &matrix);

private:
    unsigned int rows_;
    unsigned int columns_;
    std::vector<std::vector<double>> coef_;
};

std::ostream & operator<<(std::ostream & stream, Matrix const & matrix);
Matrix operator+(Matrix const & a, Matrix const & b);
Matrix operator*(double k, Matrix const & a);
Matrix operator*(Matrix const & a, Matrix const & b);


#endif //MATRIX_HPP
