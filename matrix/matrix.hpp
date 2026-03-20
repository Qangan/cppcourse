#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>
#include <vector>

class Matrix {
public:
  Matrix();
  Matrix(std::size_t n);
  Matrix(const std::vector<double> &diag);
  Matrix(const Matrix &other);
  Matrix(Matrix &&other);
  ~Matrix();

  Matrix &operator=(const Matrix &other);
  Matrix &operator=(Matrix &&other);

  operator double() const;

  double *operator[](std::size_t i);
  const double *operator[](std::size_t i) const;
  double &operator[](std::size_t i, std::size_t j);
  const double &operator[](std::size_t i, std::size_t j) const;

  Matrix &operator+=(const Matrix &other);
  Matrix &operator-=(const Matrix &other);
  Matrix &operator*=(double scalar);
  Matrix &operator*=(const Matrix &other);

  friend Matrix operator+(const Matrix &a, const Matrix &b);
  friend Matrix operator-(const Matrix &a, const Matrix &b);
  friend Matrix operator*(const Matrix &m, double scalar);
  friend Matrix operator*(double scalar, const Matrix &m);
  friend Matrix operator*(const Matrix &a, const Matrix &b);

  friend bool operator==(const Matrix &a, const Matrix &b);
  friend bool operator!=(const Matrix &a, const Matrix &b);

  std::size_t size() const;

private:
  std::size_t n;
  double *data;
};

#endif
