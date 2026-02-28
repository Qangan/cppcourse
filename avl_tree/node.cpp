#ifndef NODE_CPP
#define NODE_CPP
#include "node.hpp"
template <std::totally_ordered T>
Node<T>::Node(T value)
    : value(value), left(nullptr), right(nullptr), height(1) {}
#endif
