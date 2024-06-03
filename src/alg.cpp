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
        std::cout << "File error!" << std::endl;
        return BST<std::string>();
    }
    char symbol;
    std::string word;
    BST<std::string> tree;
    while (file.get(symbol)) {
        if ((symbol >= 'A' && symbol <= 'Z')
            || (symbol >= 'a' && symbol <= 'z')) {
            if (symbol >= 'A' && symbol <= 'Z') {
                symbol = symbol + ('a' - 'A');
            }
            word += symbol;
        } else if (!word.empty()) {
            tree.add(word);
            word.clear();
        }
    }
    file.close();
    return tree;

}
