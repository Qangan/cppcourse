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

  return 0;
}
