// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> Der;
  std::string word = "";
std::ifstream file(filename);
if (!file) {
    std::cout << "File error!" << std::endl;
    return Der;
}
while (!file.eof()) {
    char sign = file.get();
    if (sign <= 'Z' && sign >= 'A') {
        sign = sign + ('a' - 'A');
    }
    if (sign <= 'z' && sign >= 'a') {
        word += sign;
    } else {
        Der.add(word);
        word = "";
    }
}
file.close();
return Der;
}
