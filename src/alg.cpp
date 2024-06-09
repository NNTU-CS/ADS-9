// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

bool isLatinLetter(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}
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
        if (isLatinLetter(ch)) {
            word += std::tolower(ch, std::locale());
        } else if (!word.empty()) {
            tree.insert(word);
            word.clear();
        }
    }

    if (!word.empty()) {
        tree.insert(word);
    }

    file.close();
    return tree;
}
