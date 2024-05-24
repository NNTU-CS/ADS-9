// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <cstdlib>
#include  <string>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string word;
        while (file >> word) {
            for (char& ch : word) {
                ch = std::tolower(ch);
            }
            bool valid = true;
            for (char ch : word) {
                if (!std::isalpha(ch)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                tree.insert(word);
            }
        }
        file.close();
    }
    return tree;
}
