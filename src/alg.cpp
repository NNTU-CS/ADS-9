// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream fin(filename);
    if (!fin) {
        exit(1);
    }
    BST<std::string> t;
    std::string str;
    while (!fin.eof()) {
        char ch;
        fin.get(ch);
        if (isalpha(ch)) {
            str += tolower(ch);
        } else if (!str.empty()) {
            t.add(str);
            str.clear();
        }
    }
    fin.close();
    return t;
}
