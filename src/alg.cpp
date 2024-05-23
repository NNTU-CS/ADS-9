// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <sstream>
#include  <cctype>
#include  <algorithm>
#include  <string>
#include  "bst.h"

BST<std::string>* makeTree(const char* filename) {
    BST<std::string>* bst = new BST<std::string>();
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        exit(1);
    }

    std::string word;
    while (file >> word) {
        bst->add(word);
    }

    file.close();
    return bst;
}
