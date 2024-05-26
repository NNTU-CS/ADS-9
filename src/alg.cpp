// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    std::string word;
    BST<std::string> binTree;

    if (!file) {
        std::cout << "File error!" << std::endl;
        return binTree;
    }
    while (!file.eof()) {
        char s = file.get();
        if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z')) {
            word += tolower(s);
        } else {
            binTree.add(word);
            word.clear();
        }
    }
    file.close();
    return binTree;
}
