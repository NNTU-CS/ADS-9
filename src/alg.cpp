// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
    if (!file) {
        std::cout << "Error is here" << std::endl;
    }
    BST<std::string> tree;
    char char1;
    char *chu = new char;
    int counter = 0;
    std::string stringg;
    std::vector<std::string> vec;
    while (!file.eof()) {
        file.get(char1);
        if ((char1 > 64 && char1 < 91) || (char1 > 96 && char1 < 123)) {
            chu[counter] = tolower(char1);
            counter++;
        } else {
            for (int i = 0; i < counter; i++) {
                stringg += chu[i];
            }
            if (stringg != "") {
                vec.push_back(stringg);
            }
            stringg = "";
            counter = 0;
        }
    }
    while (!vec.empty()) {
        tree.add(vec.back());
        vec.pop_back();
    }
    file.close();
    return tree;
}
