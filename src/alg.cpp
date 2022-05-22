// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string>tree;
  char lowercase = 'a' - 'A';
  std::ifstream file(filename);
  if (!file) {
    std::cout << "Error!" << std::endl;
    return tree;
  }
  std::string word = "";
  while (!file.eof()) {
    char temp = file.get();
    if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z')) {
      if (temp >= 'A' && temp <= 'Z')
        temp += lowercase;
      word += temp;
    } else if (word != "") {
      tree.add(word);
      word = "";
    }
  }
  file.close();
  return tree;
}
