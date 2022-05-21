// Copyright 2022 Matvey Ryabchikov
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <locale>

#include "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> bst;
  std::ifstream file(filename);
  std::string word = "";
  if (!file.is_open()) throw std::string("Error! File did not open!");
  while (!file.eof()) {
    word = "";
    while (true) {
      char character = file.get();
      if ((character >= 'a' && character <= 'z') ||
          (character >= 'A' && character <= 'Z'))
        word += tolower(character);
      else
        break;
    }
    bst.add(word);
  }
  return bst;
}
