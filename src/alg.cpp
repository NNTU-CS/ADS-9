// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> Tr;
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return Tr;
    }
    char s;
    std::string wd = "";
    while (!file.eof()) {
        s = file.get();
        if (s <= 'Z' && s >= 'A') {
            s = s + ('a' - 'A');
        }
        if (s <= 'z' && s >= 'a') {
            wd += s;
        } else {
            Tr.add(wd);
            wd = "";
        }
    }
    file.close();
    return Tr;
}
