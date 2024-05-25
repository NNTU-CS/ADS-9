// Copyright 2021 NNTU-CS
// alg.cpp

#include "bst.h"
#include <fstream>
#include <string>
#include <cctype>

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "File error!" << std::endl;
        return tree;
    }

    std::string word;
    char ch;

    while (file.get(ch)) {
        if (std::isalpha(ch)) {
            word += std::tolower(ch);
        } else if (!word.empty()) {
            tree.insert(word);
            word.clear();
        }
    }
    //Вставьте последнее слово, если файл заканчивается на букву
    if (!word.empty()) {
        tree.insert(word);
    }

    file.close();
    return tree;
}
