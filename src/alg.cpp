// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> TR;
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return TR;
    }
    char e;
    std::string mr = "";
    while (!file.eof()) {
        e = file.get();
        if (e >= 'A' && e <= 'Z') {
            e = e + ('a' - 'A');
        }
        if (e >= 'a' && e <= 'z') {
            mr = mr + e;
        } else {
            TR.add(mr);
            mr = "";
        }
    }
    file.close();
    return TR;
}
