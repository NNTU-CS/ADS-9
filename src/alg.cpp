// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <string>
#include  "bst.h"

std::string low(std::string str) {
  std::string t;
  for (auto x = str.begin(); x != str.end(); ++x) {
    t += tolower(*x);
  }
  return t;
}
BST<std::string> makeTree(const char* filename) {
  BST<std::string> newTree;
  std::ifstream file(filename);
  std::string word;
  while (!file.eof()) {
    char let = file.get();
    if ((let >= 'a' && let <= 'z') || (let >= 'A' && let <= 'Z')) {
      word += let;
    } else {
      word = low(word);
      newTree.add(word);
      word = "";
    }
  }
  return newTree;
}


