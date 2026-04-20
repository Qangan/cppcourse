#include <type_traits>

template <int N, int D = 2>
struct IsPrime
    : std::conditional_t<
          (N < 2), std::false_type,
          std::conditional_t<(D * D > N), std::true_type,
                             std::conditional_t<(N % D == 0), std::false_type,
                                                IsPrime<N, D + 1>>>> {};

template <int N, int P = 2>
struct NthPrime
    : std::conditional_t<
          IsPrime<P>::value,
          std::conditional_t<(N == 1), std::integral_constant<int, P>,
                             NthPrime<N - 1, P + 1>>,
          NthPrime<N, P + 1>> {};
