// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> BSTtree;
    std::ifstream file(filename);
    std::string line;
    while (!file.eof()) {
        char sym = file.get();
        if (sym >= 'A' && sym <= 'Z')
            sym = sym + ('a' - 'A');
        if (sym >= 'a' && sym <= 'z') {
            line += sym;
        } else {
            BSTtree.add(line);
        line.clear();
        }
    }
    return BSTtree;
}
