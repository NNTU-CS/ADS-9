// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string>tree;
  std::string words = "";
  char lowcase = 'a' - 'A';
  std::ifstream file(filename);

  if (!file) {
    std::cout << "Error!" << std::endl;
    return tree;
  }
  while (!file.eof()) {
    char chars = file.get();
    if ((chars >= 'a' && chars <= 'z') || (chars >= 'A' && chars <= 'Z')) {
      if (chars >= 'A' && chars <= 'Z')
        chars += lowcase;
      words += chars;
    } else if (words != "") {
      tree.add(words);
      words = "";
    }
  }
  file.close();
  return tree;
}
