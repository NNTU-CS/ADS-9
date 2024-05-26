// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> BSTTree;
    std::ifstream file(filename);
    std::string line;
    while (!file.eof()) {
        char ch = file.get();
        if (ch >= 'A' && ch <= 'Z')
            ch += static_cast<char>(tolower(ch));
        if (ch >= 'a' && ch <= 'z') {
            line += ch;
        } else {
            BSTTree.addNode(line);
        line.clear();
        }
    }
    return BSTTree;
}
