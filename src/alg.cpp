// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
    std::string words = "";
    std::ifstream file(filename);

    if (!file) {
        std::cout << "The file was not found!" << std::endl;
        return tree;
    }

    while (!file.eof()) {
        char symbol = file.get();
        if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z')) {
            words += tolower(symbol);
        } else if (words != "") {
            tree.add(words);
            words = "";
        }
    }
    file.close();
    return tree;
}
