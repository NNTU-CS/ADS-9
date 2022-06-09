// Copyright 2021 thefreakestcopyrighter
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    BST<std::string> tree;
    if (!file) {
        std::cout << "error" << std::endl;
        return tree;
    }
    while (!file.eof()) {
        std::string word;
        while (isalpha(file.peek()))
            word += tolower(file.get());
        tree.add(word);
        while (!isalpha(file.peek()) && !file.eof())
            file.get();
    }
    return tree;
}
