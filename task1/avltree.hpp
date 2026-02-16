#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include "node.hpp"
#include <concepts>

template <std::totally_ordered T> class AVLTree {
public:
  AVLTree();
  Node<T> *insert(T val);
  Node<T> *remove(T val);
  void print_values();

private:
  Node<T> *_root;
  void _inorder(Node<T> *node);
  Node<T> *_insert(Node<T> *node, T val);
  Node<T> *_remove(Node<T> *node, T val);
  Node<T> *_rotate_right(Node<T> *node);
  Node<T> *_rotate_left(Node<T> *node);
  Node<T> *_rebalance(Node<T> *node);
  Node<T> *_min_node(Node<T> *node);
  int _height(Node<T> *node);
  int _balance_factor(Node<T> *node);
  void _recalc(Node<T> *node);
};

#include "avltree.cpp"

#endif
