// Copyright 2021 NNTU-CS
#include <string>
#include <fstream>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> bst;
  std::ifstream file(filename);
  std::string word = "";
  if (!file.is_open()) {
    throw std::string("Error! File did not open!");
  }
  while (!file.eof()) {
    word = "";
    while (true) {
      char plus = file.get();
      if ((plus >= 65 && plus <= 90) || (plus >= 97 && plus <= 122)) {
        word += tolower(plus);
      } else {
          break;
        }
    }
    bst.Add(word);
  }
  return bst;
}

