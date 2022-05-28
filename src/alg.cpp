// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include  <cstdlib>
#include <string>
#include <algorithm>
#include "bst.h"


BST<std::string> makeTree(const char* filename) {
    BST<std::string> BSTree;
    std::string str;
    std::string value;
    std::ifstream fin(filename);
    if (!fin) {
        std::cout << "File error, try again!" << std::endl;
    }
    while (!fin.eof()) {
        while (true) {
            char tmp = fin.get();
            if ((tmp >= 65 && tmp <= 90) || (tmp >= 97 && tmp <= 122)) value += tolower(tmp);
            else
                break;
        }
        BSTree.addNode_(value);
        value = "";
    }
    return BSTree;
}
