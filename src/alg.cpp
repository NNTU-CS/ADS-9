// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* name) {
  BST<std::string> Tree;
  char ch;
  std::ifstream file(name);
  std::string t = "";
  std::string word = t;
  while (!file.eof()) {
    ch = file.get();
    if ((ch >= 'A') && (ch <= 'Z')) ch += 32;
    if ((ch >= 'a') && (ch <= 'z')) {
      word += ch;
    } else {
      Tree.add(word);
      word = t;
    }
  }
  file.close();
  return Tree;
}
