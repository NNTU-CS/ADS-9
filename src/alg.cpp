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
        std::cerr << "Error opening file: " << filename << std::endl;
        return tree;
    }

    std::string word;
    char ch;

    while (file.get(ch)) {
        if (isalpha(ch)) {
            word += tolower(ch); // Преобразование в нижний регистр
        } else if (!word.empty()) {
            tree.insert(word);
            word.clear();
        }
    }

    if (!word.empty()) { // Обработка последнего слова
        tree.insert(word);
    }

    file.close();
    return tree;
}
