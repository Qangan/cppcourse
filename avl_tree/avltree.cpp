#ifndef AVLCPP
#define AVLCPP
#include "avltree.hpp"
#include <algorithm>
#include <concepts>
#include <iostream>

template <std::totally_ordered T> Node<T> *AVLTree<T>::insert(T value) {
  _root = _insert(_root, value);
  return _root;
}

template <std::totally_ordered T> Node<T> *AVLTree<T>::remove(T value) {
  _root = _remove(_root, value);
  return _root;
}

template <std::totally_ordered T>
Node<T> *AVLTree<T>::_insert(Node<T> *node, T value) {
  if (node == nullptr) {
    node = new Node<T>(value);
    return node;
  }
  if (value < node->value) {
    node->left = _insert(node->left, value);
  } else if (value > node->value) {
    node->right = _insert(node->right, value);
  }
  _recalc(node);
  return _rebalance(node);
}

template <std::totally_ordered T>
Node<T> *AVLTree<T>::_remove(Node<T> *node, T value) {
  if (node == nullptr) {
    return nullptr;
  }
  if (value < node->value) {
    node->left = _remove(node->left, value);
  } else if (value > node->value) {
    node->right = _remove(node->right, value);
  } else {
    if (!node->left || !node->right) {

      Node<T> *retnode = node->left ? node->left : node->right;
      delete node;
      return retnode;
    }
    Node<T> *succ = _min_node(node->right);
    node->value = succ->value;
    node->right = _remove(node->right, succ->value);
  }
  _recalc(node);
  return _rebalance(node);
}

template <std::totally_ordered T>
Node<T> *AVLTree<T>::_rotate_left(Node<T> *node) {
  Node<T> *y = node->right;
  Node<T> *T2 = y->left;
  y->left = node;
  node->right = T2;
  _recalc(node);
  _recalc(y);
  return y;
}

template <std::totally_ordered T>
Node<T> *AVLTree<T>::_rotate_right(Node<T> *node) {
  Node<T> *x = node->left;
  Node<T> *T2 = x->right;
  x->right = node;
  node->left = T2;
  _recalc(node);
  _recalc(x);
  return x;
}

template <std::totally_ordered T> int _h(Node<T> *node) {
  return node ? node->height : 0;
}

template <std::totally_ordered T> void AVLTree<T>::_recalc(Node<T> *node) {
  node->height = 1 + std::max(_h(node->left), _h(node->right));
}

template <std::totally_ordered T>
int AVLTree<T>::_balance_factor(Node<T> *node) {
  return _h(node->left) - _h(node->right);
}

template <std::totally_ordered T>
Node<T> *AVLTree<T>::_rebalance(Node<T> *node) {
  int bf = _balance_factor(node);
  if (bf > 1) {
    if (_balance_factor(node->left) < 0) {
      node->left = _rotate_left(node->left);
    }
    return _rotate_right(node);
  }
  if (bf < -1) {
    if (_balance_factor(node->right) > 0) {
      node->right = _rotate_right(node->right);
    }
    return _rotate_left(node);
  }
  return node;
}

template <std::totally_ordered T>
Node<T> *AVLTree<T>::_min_node(Node<T> *node) {
  Node<T> *x = node;
  while (x->left) {
    x = x->left;
  }
  return x;
}

template <std::totally_ordered T> void AVLTree<T>::_inorder(Node<T> *node) {
  if (!node) {
    return;
  }
  _inorder(node->left);
  std::cout << node->value << " ";
  _inorder(node->right);
}

template <std::totally_ordered T> void AVLTree<T>::print_values() {
  _inorder(_root);
  std::cout << '\n';
}

template <std::totally_ordered T> AVLTree<T>::AVLTree() : _root(nullptr) {}

template <std::totally_ordered T>
AVLTree<T>::AVLTree(const AVLTree &other) : _root(_clone(other._root)) {}

template <std::totally_ordered T>
AVLTree<T>::AVLTree(AVLTree &&other) : _root(other._root) {
  other._root = nullptr;
}

template <std::totally_ordered T> AVLTree<T>::~AVLTree() {
  _destroy(_root);
  _root = nullptr;
}

template <std::totally_ordered T> void AVLTree<T>::_destroy(Node<T> *node) {
  if (!node)
    return;

  _destroy(node->left);
  _destroy(node->right);

  delete node;
}

template <std::totally_ordered T>
Node<T> *AVLTree<T>::_clone(const Node<T> *node) {
  if (!node)
    return nullptr;
  Node<T> *copy = new Node<T>(node->value);
  copy->height = node->height;
  copy->left = _clone(node->left);
  copy->right = _clone(node->right);
  return copy;
}

template <std::totally_ordered T>
AVLTree<T> &AVLTree<T>::operator=(const AVLTree &other) {
  if (this != &other) {
    _destroy(_root);
    _root = _clone(other._root);
  }
  return *this;
}

template <std::totally_ordered T>
AVLTree<T> &AVLTree<T>::operator=(const AVLTree &&other) {
  if (this != &other) {
    _root = other._root;
    other._root = nullptr;
  }
  return *this;
}
#endif
