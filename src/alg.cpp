// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return tree;
  }
  std::string word;
  while (file >> word) {
    for (char& c : word) {
      c = std::tolower(c);
    }
    tree.add(word);
  }
  file.close();

  return tree;
}

int main() {
  const char* filename = "src/war_peace.txt";
  BST<std::string> tree = makeTree(filename);
  for (int i = 0; i < 10; i++) {
    std::string mostFrequentWord;
    int maxCount = 0;
    tree.searchTree(tree.root, mostFrequentWord, maxCount);
    std::cout << mostFrequentWord << ": " << maxCount << std::endl;
  }
  return 0;
}
