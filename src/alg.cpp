// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <string>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    // поместите сюда свой код
    BST<std::string> tree;
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        throw std::string("Can not open file!");
    }
    std::string word = "";
    while (!file.eof()) {
        char ch = file.get();
        int code = ch;
        if ((code >= 65 && code <= 90) || (code >= 97 && code <= 122)) {
            word += tolower(code);
        } else {
            if (word != "") {
                tree.Add(word);
                word = "";
            }
        }
    }
    file.close();
    return tree;
}


