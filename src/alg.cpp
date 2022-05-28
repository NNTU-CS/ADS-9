// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <string>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> bst;
  std::ifstream file(filename);
  std::string word = "";
  char lowercase = 'a' - 'A';
  if (!file.is_open()) {
    throw std::string("Error! the file was not opened.");
  }
  while (!file.eof()) {
    char temp = file.get();
    if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z')) {
      if (temp >= 'A' && temp <= 'Z')
        temp += lowercase;
      word += temp;
    } else if (word != "") {
      bst.add(word);
      word = "";
    }
  }
  file.close();
  return bst;
}
