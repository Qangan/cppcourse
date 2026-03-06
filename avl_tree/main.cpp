#include "avltree.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main() {
  srand(time(nullptr));
  AVLTree<int> tree;
  std::vector<int> values;
  int tree_max = rand() % 1000;
  int val;

  for (int i = 0; i < tree_max; i += (1 + rand() % 25)) {
    tree.insert(i);
    values.push_back(i);
  }

  tree.print_values();

  for (int i = 0; i < 10; i++) {
    if (values.size() == 0)
      break;
    val = values[rand() % values.size()];
    tree.remove(val);
    values.erase(std::remove(values.begin(), values.end(), val), values.end());
  }

  for (auto i = values.begin(); i < values.end(); i++) {
    std::cout << *i << " ";
  }

  std::cout << std::endl;
  tree.print_values();

  AVLTree<std::string> stringTree;

  stringTree.insert("banana");
  stringTree.insert("apple");
  stringTree.insert("cherry");
  stringTree.insert("date");

  stringTree.print_values();

  AVLTree<int> copyTree(tree);
  std::cout << "original: ";
  tree.print_values();
  std::cout << "copied: ";
  copyTree.print_values();

  AVLTree<int> assignedTree;
  assignedTree.insert(1);
  assignedTree.insert(2);
  assignedTree.insert(3);

  std::cout << "before: ";
  assignedTree.print_values();
  assignedTree = tree;
  std::cout << "after: ";
  assignedTree.print_values();
  std::cout << "meanwhile: ";
  tree.print_values();

  AVLTree<int> src;
  src.insert(10);
  src.insert(5);
  src.insert(15);
  std::cout << "move src: ";
  src.print_values();
  AVLTree<int> moveTree(std::move(src));
  std::cout << "move dst: ";
  moveTree.print_values();

  src.insert(1);
  std::cout << "src after move+insert: ";
  src.print_values();
  src.remove(1);
  AVLTree<int> emptyMoved(std::move(src));
  emptyMoved.insert(99);
  std::cout << "moved from empty, inserted 99: ";
  emptyMoved.print_values();

  AVLTree<int> a;
  a.insert(3);
  a.insert(7);
  AVLTree<int> b(std::move(a));
  b.insert(1);
  b.insert(9);
  std::cout << "b after move+inserts: ";
  b.print_values();
  a.insert(100);
  std::cout << "a after own insert: ";
  a.print_values();
  return 0;
}
