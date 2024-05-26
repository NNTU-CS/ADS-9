// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <string>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::string("ERROR file.");
    }
    std::string currentWord = "";
    BST<std::string> mytree;
    while (!file.eof()) {
        currentWord = "";
        while (true) {
            char cursymbol = file.get();
            if ((cursymbol >= 65 && cursymbol <= 90) || (cursymbol >= 97 && cursymbol <= 122)) {
                currentWord += tolower(cursymbol);
            } else {
                break;
            }
        }
        if (!currentWord.empty()) {
            mytree.add(currentWord);
        }
    }
    file.close();
    return mytree;
}
