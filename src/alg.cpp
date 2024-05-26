// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makevetki(const char* filename) {
    BST<std::string> branches;
    std::ifstream file(filename);
    char letter;
    std::string say = "";
    if (!file.is_open()) {
        std::cout << "File error!" << std::endl;
        return branches;
    }
    while (!file.eof()) {
        letter = file.get();
        if ((letter >= 'A') && (letter <= 'Z'))
            letter += 32;
        if ((letter >= 'a') && (letter <= 'z')) {
            say += letter;
        } else {
            branches.Plus(say);
            say = "";
        }
    }
    file.close();
    return branches;
}