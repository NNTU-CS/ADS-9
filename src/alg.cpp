// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <vector>

#include  "bst.h"

BST<std::string> makeTree(const char *filename) {
    std::ifstream file(filename);
    vector<string> text;
    if (!file) {
        std::cout << "File error!" << std::endl;
    }
    BST<std::string> tree;
    int count = 0;
    std::string slovo;
    std::vector<std::string> text;
    while (!file.eof()) {
        char ch = file.get();
        ch = tolower(ch);
        if (ch >= 97 && ch <= 122) {
            slovo+= ch;
        } else {
            text.push_back(slovo);
            slovo = "";
        }
        count++;
    }
    for (int i = text.size; i > 0; i--) {
        tree.add(text[i]);
        text.pop_back();
    }
    file.close();
    return tree;
}
