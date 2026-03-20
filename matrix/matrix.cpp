#include "matrix.hpp"
#include <algorithm>
#include <cassert>
#include <cstddef>

Matrix::Matrix() : n(0), data(nullptr) {}

Matrix::Matrix(std::size_t n_) : n(n_), data(nullptr) {
  if (n == 0) {
    data = nullptr;
  } else {
    data = new double[n * n]();
  }
}

Matrix::Matrix(const std::vector<double> &diag)
    : n(diag.size()), data(nullptr) {
  if (n == 0) {
    data = nullptr;
    return;
  }
  data = new double[n * n]();
  for (std::size_t i = 0; i < n; ++i) {
    data[i * n + i] = diag[i];
  }
}

Matrix::Matrix(const Matrix &other) : n(other.n), data(nullptr) {
  if (n == 0) {
    data = nullptr;
    return;
  }
  data = new double[n * n];
  std::copy(other.data, other.data + n * n, data);
}

Matrix::Matrix(Matrix &&other) : n(other.n), data(other.data) {
  other.n = 0;
  other.data = nullptr;
}

Matrix::~Matrix() { delete[] data; }

Matrix &Matrix::operator=(const Matrix &other) {
  if (this != &other) {
    if (n != other.n) {
      delete[] data;
      n = other.n;
      data = n ? new double[n * n] : nullptr;
    }
    if (n) {
      std::copy(other.data, other.data + n * n, data);
    }
  }
  return *this;
}

Matrix &Matrix::operator=(Matrix &&other) {
  if (this != &other) {
    delete[] data;
    n = other.n;
    data = other.data;
    other.n = 0;
    other.data = nullptr;
  }
  return *this;
}

Matrix::operator double() const {
  double sum = 0;
  for (std::size_t i = 0; i < n * n; ++i) {
    sum += data[i];
  }
  return sum;
}

double *Matrix::operator[](std::size_t i) { return data + i * n; }

const double *Matrix::operator[](std::size_t i) const { return data + i * n; }

double &Matrix::operator[](std::size_t i, std::size_t j) {
  return data[i * n + j];
}
const double &Matrix::operator[](std::size_t i, std::size_t j) const {
  return data[i * n + j];
}
Matrix &Matrix::operator+=(const Matrix &other) {
  assert(n == other.n);
  for (std::size_t i = 0; i < n * n; ++i) {
    data[i] += other.data[i];
  }
  return *this;
}

Matrix &Matrix::operator-=(const Matrix &other) {
  assert(n == other.n);
  for (std::size_t i = 0; i < n * n; ++i) {
    data[i] -= other.data[i];
  }
  return *this;
}

Matrix &Matrix::operator*=(double scalar) {
  for (std::size_t i = 0; i < n * n; ++i) {
    data[i] *= scalar;
  }
  return *this;
}

Matrix &Matrix::operator*=(const Matrix &other) {
  assert(other.n == n);
  Matrix tmp(n);
  for (std::size_t i = 0; i < n; ++i) {
    for (std::size_t j = 0; j < n; ++j) {
      for (std::size_t k = 0; k < n; ++k) {
        tmp[i][j] += (*this)[i][k] * other[k][j];
      }
    }
  }
  *this = tmp;
  return *this;
}
Matrix operator+(const Matrix &a, const Matrix &b) {
  Matrix res(a);
  res += b;
  return res;
}

Matrix operator-(const Matrix &a, const Matrix &b) {
  Matrix res(a);
  res -= b;
  return res;
}

Matrix operator*(const Matrix &m, double scalar) {
  Matrix res(m);
  res *= scalar;
  return res;
}

Matrix operator*(double scalar, const Matrix &m) { return m * scalar; }

Matrix operator*(const Matrix &a, const Matrix &b) {
  Matrix res(a);
  res *= b;
  return res;
}

bool operator==(const Matrix &a, const Matrix &b) {
  if (a.n != b.n)
    return false;
  for (std::size_t i = 0; i < a.n * a.n; ++i) {
    if (a.data[i] != b.data[i])
      return false;
  }
  return true;
}

bool operator!=(const Matrix &a, const Matrix &b) { return !(a == b); }

std::size_t Matrix::size() const { return n; }
