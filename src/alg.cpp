// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
BST<std::string> makeTree(const char* filename) {
  BST<std::string>Tree;
  std::string word = "";
  char lowercase = 'a' - 'A';
  std::ifstream file(filename);
  if (!file) {
    std::cout << "Error!" << std::endl;
    return Tree;
  }
  while (!file.eof()) {
    char ch = file.get();
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
      if (ch >= 'A' && ch <= 'Z')
        ch += lowercase;
      word += ch;
    } else if (word != "") {
      Tree.add(word);
      word = "";
    }
  }
  file.close();
  return Tree;
}
