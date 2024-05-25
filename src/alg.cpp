// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    for (char& c : lowerStr) {
        c = tolower(c);
    }
    return lowerStr;
}

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "File error!" << std::endl;
        return;
    }
    std::string word;
    char ch;
    while (file.get(ch)) {
        if (isalpha(ch)) {
            word += ch;
        }
        else {
            if (!word.empty()) {
                tree.insert(toLower(word));
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        tree.insert(toLower(word));
    }
    file.close();
    return tree;
}
