// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
    std::string line;
    std::string text;
    std::string push;
    while (std::getline(line, file)) {
        text = text + line + " ";
    }
    for (auto c : text) {
        if (isalpha(c)) {
            c = tolower(c);
            push += c;
        }
        else {
            tree.addElement(push);
            push = "";
        }
    }

    file.close();
    return tree;
}
