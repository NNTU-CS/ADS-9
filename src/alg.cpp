// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <sstream>
#include <string>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::ifstream file(filename);
  if(file.is_open()) {
    std::string word;
    while (file >> word) {
        std::stringstream ss;
        for(char c : word) {
            if (std::isalpha(c)) {
                ss << (char)std::tolower(c);
            }
        }
        if (ss.str().empty()) {
            tree.add(ss.str());
        }
    }
    file.close();
  }
  return tree;
}
