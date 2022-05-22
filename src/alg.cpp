// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <string>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> bst;
  std::ifstream file(filename);
  std::string word = "";
  char lwcase = 'a' - 'A';
  if (!file.is_open()) {
    throw std::string("Error! the file was not opened.");
  }
  while (!file.eof()) {
    char temp = file.get();
    if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z')) {
      if (temp >= 'A' && temp <= 'Z')
        temp += lwcase;
      word += temp;
    } else if (word != "") {
      bst.add(word);
      word = "";
    }
  }
  file.close();
  return bst;
}
