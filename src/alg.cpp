// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> tree;
    std::ifstream file(filename);
    std::string symboll = "";
    if (!file) {
        throw std::string("File Error!!! ");
    }
    while (!file.eof()) {
        symboll = "";
        while (true) {
            char sss = file.get();
            if ((sss >= 65 && sss <= 90) || (sss >= 97 && sss <= 122)) {
                symboll += tolower(sss);
            } else {
                break;
            }
        }
        tree.add(symboll);
    }
    file.close();
    return tree;
}
