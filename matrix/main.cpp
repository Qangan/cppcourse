#include "matrix.hpp"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>

void fill_random(Matrix &m) {
  for (std::size_t i = 0; i < m.size(); ++i) {
    for (std::size_t j = 0; j < m.size(); ++j) {
      m[i][j] = std::rand() % 1000;
    }
  }
}

int main() {
  const std::size_t N = std::rand() % 1000;

  Matrix Z(N);
  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < N; ++j) {
      assert(Z[i][j] == 0.0);
    }
  }

  std::vector<double> ones(N, 1.0);
  Matrix I(ones);
  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < N; ++j) {
      if (i == j)
        assert(I[i][j] == 1.0);
      else
        assert(I[i][j] == 0.0);
    }
  }

  Matrix A(N);
  Matrix B(N);
  fill_random(A);
  fill_random(B);

  Matrix C = A + B;
  Matrix D = C - B;
  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < N; ++j) {
      assert(C[i][j] == A[i][j] + B[i][j]);
      assert(D[i][j] == A[i][j]);
    }
  }
  assert(D == A);
  assert(C != A);

  double S = rand() % 10000;
  Matrix S1 = A * S;
  Matrix S2 = S * A;
  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < N; ++j) {
      assert(S1[i][j] == A[i][j] * S);
    }
  }
  assert(S1 == S2);

  Matrix MI1 = A * I;
  Matrix MI2 = I * A;
  assert(MI1 == A);
  assert(MI2 == A);

  double manual_sum = 0.0;
  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < N; ++j) {
      manual_sum += A[i][j];
    }
  }
  assert(static_cast<double>(A) == manual_sum);

  std::cout << "All tests passed!" << std::endl;

  return 0;
}
