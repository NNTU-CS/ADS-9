// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  std::ifstream file(filename);
    if (!file) {
        std::cout << "Error!" << std::endl;
        exit(1);
    }
    char sl;
    std::string word;
    BST<std::string> tree;
    while (file.get(sl)) {
        if (isalpha(sl)) {
            word += tolower(sl);
        } else if (!word.empty()) {
            tree.add(word);
            word.clear();
        }
    }
    file.close();
    return tree;
}
