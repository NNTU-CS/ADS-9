// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <algorithm>
#include "bst.h"

char toLowerChar(char ch) {
    return std::tolower(ch, std::locale::classic());
}

bool isAlphaChar(char ch) {
    return std::isalpha(ch, std::locale::classic());
}

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "File error!" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string word;
    while (file >> word) {
    auto new_end = std::remove_if(
        word.begin(),
        word.end(),
        [](char c) { return !isAlphaChar(c); });
        word.erase(new_end, word.end());
        std::string filteredWord;
        std::transform(word.begin(), word.end(), std::back_inserter(filteredWord), toLowerChar);
        if (!filteredWord.empty()) {
            tree.insert(filteredWord);
        }
    }
    file.close();
    return tree;
}
