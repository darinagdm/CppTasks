#ifndef HOMEWORK19_MATRIX_H
#define HOMEWORK19_MATRIX_H

#include <ostream>
#include "vector"

struct MatrixSize{
    int rows;
    int columns;

    friend std::ostream &operator<<(std::ostream &os, const MatrixSize &size) {
        os << "rows: " << size.rows << " columns: " << size.columns;
        return os;
    }
};

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> mat;
    MatrixSize size = {0,0};

    T vecMul(std::vector<T> vec1, std::vector<T> vec2){
        T t = 0;
        if (vec1.size()!=vec2.size()) throw std::exception();
        for (int i=0; i<vec1.size(); i++){
            t += vec1[i]*vec2[i];
        }
        return t;
    }
public:
    explicit Matrix(std::vector<std::vector<T>> mat){
        size.rows = mat.size();
        if (size.rows>0){
            size.columns = mat[0].size();
        }
        for (std::vector<T> row: mat){
            if (row.size()!=size.columns){
                std::cout<<"Input vector is not a Matrix!"<< std::endl;
                throw std::exception();
            }
        }
        this->mat=mat;
    }

    const MatrixSize &getSize() const {
        return size;
    }

    const std::vector<std::vector<T>> &toVector() const {
        return mat;
    }

    bool operator==(const Matrix &other) const {
        return mat == other.mat;
    }

    bool operator!=(const Matrix &other) const {
        return other != *this;
    }

    std::vector<T>& operator[](int row_id){
        return mat[row_id];
    };

    Matrix<T> operator+(Matrix &other){
        std::vector<std::vector<T>> new_mat(mat);
        for (int i=0; i<size.rows; i++){
            for (int j=0;j<size.columns; j++){
                new_mat[i][j]+=other[i][j];
            }
        }
        Matrix newMatrix(new_mat);
        return newMatrix;
    }

    std::vector<T> operator*(const std::vector<T> vector){
        if (vector.size()!=size.columns){
            std::cout<<"Invalid vector size"<< std::endl;
            throw std::exception();
        }
        std::vector<T> mul(size.rows);
        for (int i=0; i<size.rows; i++){
            mul[i] = vecMul(mat[i],vector);
        }
        return mul;
    }

    Matrix<T> operator*(Matrix<T> other){
        other.transpose();
        std::vector<std::vector<T>> new_mat(size.rows);

        std::vector<std::vector<T>> otherMat = other.toVector();

        for (int i=0; i<otherMat.size();i++){
            new_mat[i] = (*this)*otherMat[i];
        }

        other.transpose();
        Matrix<T> m(new_mat);
        m.transpose();
        return m;
    }

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
        os << "Matrix ("<<matrix.size<<"): " << std::endl;
        for (const std::vector<T> row: matrix.mat){
            os<<"[ ";
            for (const T t: row){
                os<<t<<", ";
            }
            os<<"]"<< std::endl;
        }
        return os;
    }

    void transpose(){
        std::vector<std::vector<T>> transposed(size.columns);
        for (int i=0; i<size.columns; i++){
            std::vector<T> row(size.rows);
            for (int j=0;j<size.rows; j++){
                row[j] =  mat[j][i];
            }
            transposed[i] = row;
        }
        mat = transposed;
        MatrixSize size_new = {size.columns,size.rows};
        size = size_new;
    }
};


#endif //HOMEWORK19_MATRIX_H
