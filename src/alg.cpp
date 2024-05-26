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
    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }
    std::string word;
    while (file >> word) {
        std::string lowerWord;
        for (char c : word) {
            if (std::isalpha(c)) {
                lowerWord += std::tolower(c);
            }
        }
        if (!lowerWord.empty()) {
            tree.add(lowerWord);
        }
    }
    file.close();
    return tree;
}
