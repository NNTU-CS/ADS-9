// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }
    std::string word;
    while (file >> word) {
        std::string cleanedWord;
        for (char c : word) {
            if (isalpha(c)) {
                cleanedWord += tolower(c);
            }
        }
        if (!cleanedWord.empty()) {
            tree.insert(cleanedWord);
        }
    }
    file.close();
    return tree;
}
