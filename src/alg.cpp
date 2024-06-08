// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

char ChangeRegistr(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        ch += ('a' - 'A');
    }
    return ch;
}
BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    BST<std::string> bst;
    std::string word;
    bool flag = false;
    char ch;
    while (!file.eof()) {
        ch = file.get();
        ch = ChangeRegistr(ch);
        if (ch >= 'a' && ch <= 'z') {
            if (!flag) {
                flag = true;
                word = ch;
            } else {
                word += ch;
            }
        } else {
            flag = false;
            bst.add(word);
            word = "";
        }
    }
    file.close();
    return bst;
}
