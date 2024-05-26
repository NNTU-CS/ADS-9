// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
   BST<std::string> tree;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return tree;
    }

    std::string word;
    while (file >> word) {
        std::string filteredWord;
        for (char c : word) {
            if (std::isalpha(c)) {
                filteredWord += std::tolower(c);
            }
        }
        if (!filteredWord.empty()) {
            tree.insert(filteredWord);
        }
    }

    file.close();
    return tree;
}
