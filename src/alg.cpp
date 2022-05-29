// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> T;
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return T;
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
            T.add(mr);
            mr = "";
        }
    }
    file.close();
    return T;
}
