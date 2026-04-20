#include "isprime.hpp"
#include <iostream>

int main() {
	static_assert(NthPrime<1>::value == 2);
	static_assert(NthPrime<2>::value == 3);
	static_assert(NthPrime<3>::value == 5);
	static_assert(NthPrime<4>::value == 7);
	static_assert(NthPrime<5>::value == 11);
	static_assert(NthPrime<6>::value == 13);
	static_assert(NthPrime<7>::value == 17);
	static_assert(NthPrime<8>::value == 19);
	static_assert(NthPrime<9>::value == 23);
	static_assert(NthPrime<10>::value == 29);
}
