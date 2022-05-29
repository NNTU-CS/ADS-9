// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> Ttree;
    std::ifstream file(filename);

    if (!file) {
        std::cout << "File error!" << std::endl;
        return Ttree;
    }
    char ch;
    std::string word = "";
    while (!file.eof()) {
        ch = file.get();
        if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) {
            word += tolower(ch);
        } else {
            Ttree.add(word);
            word = "";
        }
    }

    file.close();
    return Ttree;
}
