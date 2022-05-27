// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
    std::ifstream file(filename);
    if (!file) {
        throw std::string("File Error!!! ");
    }
    std::string sim = "";
    while (!file.eof()) {
        sim = "";
        while (true) {
            char simv = file.get();
            if ((simv > 64 && simv < 91) || (simv > 96 && simv < 123)) {
                sim += tolower(simv);
            } else {
                break;
            }
        }
        tree.add(sim);
    }
    file.close();
    return tree;
}
