#ifndef NODE_HPP
#define NODE_HPP
#include <concepts>
template <std::totally_ordered T> class Node {
public:
  T value;
  Node *left;
  Node *right;
  int height;
  Node(T value);
};

#include "node.cpp"

#endif
