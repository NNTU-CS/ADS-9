// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
bool checkLetter(char* ch) {
    int kol = 0;
    for (int i = 65; i < 91; ++i) {
        if (*ch == i) {
            *ch = 97 + kol;
            return true;
        }
        ++kol;
    }
    for (int i = 97; i < 123; ++i) {
        if (*ch == i) {
            return true;
        }
    }
    return false;
}
BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    std::string res;
    BST<std::string> bst;
    while (!file.eof()) {
        char ch = file.get();
        if (!checkLetter(&ch)) {
            bst.add(res);
            res = "";
        } else if (checkLetter(&ch)) {
            res += ch;
        }
    }
    file.close();
    return bst;
}
