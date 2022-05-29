// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::fstream file(filename);
    if (!file) {
        std::cout << "Ошибка файла" << std::endl;
        return tree;
    }
    std::string str;
    while (!file.eof()) {
        char chr = file.get();
        if (chr >= 'A' && chr <= 'Z') {
            str += std::tolower(chr);
        } else if (chr >= 'a' && chr <= 'z') {
            str += chr;
        } else {
            if (str != "") {
                tree.add(str);
            }
            str.clear();
        }
    }
    if (str != "") {
        tree.add(str);
    }
    file.close();
    return tree;
}
