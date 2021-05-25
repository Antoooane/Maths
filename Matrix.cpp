#include "Matrix.hpp"
#include <stdexcept>

Matrix::Matrix(unsigned int rows, unsigned int columns) {
    if (rows == 0 || columns == 0) {
        throw std::runtime_error ("Matrix has size of 0");
    }
    rows_ = rows;
    columns_ = columns;
    coef_ = std::vector<std::vector<double>>(rows_, std::vector<double>(columns_, 0));
}

Matrix::Matrix(unsigned int rows, unsigned int columns, std::vector<std::vector<double>> const & coef) {
    if (rows == 0 || columns == 0) {
        throw std::runtime_error("Matrix has size of 0");
    }
    rows_ = rows;
    columns_ = columns;
    coef_ = coef;
    while (coef_.size() > rows_) {
        coef_.pop_back();
    }
    while (coef_.size() < rows_)
    {
        coef_.push_back(std::vector<double>(columns_, .0));
    }

    for (unsigned int i = 0; i < coef_.size(); i++) {
        while (coef_[i].size() > columns_) {
            coef_[i].pop_back();
        }
        while (coef_[i].size() < columns_)
        {
            coef_[i].push_back(.0);
        }
    }
}

double Matrix::operator()(unsigned int r, unsigned int c) const {
    if (r > rows_ || r < 1 || c > columns_ || c < 1) {
        throw std::out_of_range ("matrix not enough big");
    } else {
        return coef_[r - 1][c - 1];
    }
}

unsigned int Matrix::getRows() const { return rows_; }

unsigned int Matrix::getColumns() const { return columns_; }

std::ostream & operator<<(std::ostream & stream, Matrix const & matrix) {
    for (unsigned int i=1; i <= matrix.getRows(); i++) {
        for (unsigned int j=1; j <= matrix.getColumns(); j++) {
            stream << matrix(i,j) << " ";
        }
        stream << "\n";
    }
    stream << std::endl;
    return stream;
}

Matrix operator+(Matrix const & a, Matrix const & b) {
    if (a.getRows() != b.getRows() || a.getColumns() != b.getColumns()) {
        throw std::runtime_error ("Not same size");
    } else {
        std::vector<std::vector<double>> coef = std::vector<std::vector<double>>(a.getRows(), std::vector<double>(a.getColumns(), .0));
        for (unsigned int i = 1; i <= a.getRows(); i++) {
            for (unsigned int j = 1; j <= a.getColumns(); j++) {
                coef[i-1][j-1] = a(i, j) + b(i, j);
            }
        }
        return Matrix(a.getRows(), a.getColumns(), coef);
    }
}

Matrix operator*(double k, Matrix const & a) {
    std::vector<std::vector<double>> coef = std::vector<std::vector<double>>(a.getRows(), std::vector<double>(a.getColumns(), .0));
    for (unsigned int i = 1; i <= a.getRows(); i++)
    {
        for (unsigned int j = 1; j <= a.getColumns(); j++)
        {
            coef[i-1][j-1] = k*a(i, j);
        }
    }
    return Matrix(a.getRows(), a.getColumns(), coef);
}

Matrix operator*(Matrix const & a, Matrix const & b) {
    if (a.getColumns() != b.getRows()) {
        throw std::runtime_error ("Not valid size");
    } else {
        std::vector<std::vector<double>> coef = std::vector<std::vector<double>>(a.getRows(), std::vector<double>(b.getColumns(), .0));
        for (unsigned int i=1; i <= a.getRows(); i++) {
            for (unsigned int j=1; j <= b.getColumns(); j++) {
                for (unsigned int k=1; k <= a.getColumns(); k++) {
                    coef[i-1][j-1] += a(i, k) * b(k, j);
                }
            }
        }
        return Matrix(a.getRows(), b.getColumns(), coef);
    }
}

double Matrix::det(Matrix const & matrix) {
    if (matrix.getRows() != matrix.getColumns()) {
        throw std::runtime_error ("Cannot compute determinant of non-square matrix");
    } else {
        if (matrix.getRows() == 2) {
            return matrix(1, 1) * matrix(2, 2) - matrix(1, 2) * matrix(2, 1);
        } else {
            double det = 0;
            for (int i=0; i < getRows(); i++) {
                std::vector<std::vector<double>> new_coef = coef_;
                new_coef.erase(std::begin(new_coef));
                for (int j=0; j < getRows(); j++) {
                    
                }
            }
            
        }
    }
}

int main()
{
    std::vector<std::vector<double>> coefs1 = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<double>> coefs2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix m1(2,3,coefs1);
    Matrix m2(3,3,coefs2);
    Matrix m3 = m1*m2;
    std::cout << m3 << std::endl;
}


