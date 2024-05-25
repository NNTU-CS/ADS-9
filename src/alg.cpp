// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> bst;
  std::ifstream file(filename);
  std::string word;
  while (!file.eof()) {
    char str = file.get();
    if (str >= 'A' && str <= 'Z')
        str = str + tolower(str);
    if (str >= 'a' && str <= 'z') {
      word += str;
    } else {
      BSTtree.add(word);
      word.clear();
    }
  }
  return BSTtree;
} 
