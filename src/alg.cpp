// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    // поместите сюда свой код
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        exit(1);
    }
    std::string a;
    char n;
    BST<std::string> tr;
    while (file.get(n)) {
        if (!a.empty()) {
            tr.append(a);
            a.clear();
        } else if (isalpha(n)) {
            a += tolower(n);
        }
    }
    file.close();
    return tr;
}
