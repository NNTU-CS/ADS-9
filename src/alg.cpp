// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <string>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> Tree;
    std::ifstream FileO(filename);
    if (!FileO) {
        throw std::string("file not open!");
    }
    std::string word = "";
    while (!FileO.eof()) {
        char temp = FileO.get();
        int symbol = temp;
        if ((symbol >= 65 && symbol <= 90) || (symbol >= 97 && symbol <= 122)) {
            word += tolower(symbol);
        } else {
            if (word != "") {
                Tree.Add_NodeT(word);
                word = "";
            }
        }
    }
    FileO.close();
    return Tree;
}

