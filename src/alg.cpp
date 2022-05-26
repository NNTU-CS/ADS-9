// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> Tree;
  std::string word = "";
std::ifstream file(filename);
if (!file) {
    std::cout << "File error!" << std::endl;
    return Tree;
}
while (!file.eof()) {
    char sign = file.get();
    if (sign <= 'Z' && sign >= 'A') {
        sign = sign + ('a' - 'A');
    }
    if (sign <= 'z' && sign >= 'a') {
        word += sign;
    } else {
        Tree.add(word);
        word = "";
    }
}
file.close();
return Tree;
}

