// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<T> makeTree(const char* filename) {
    BST<std::string> bst;
    std::ifstream file(filename);
    std::string word;
    
    if (file.is_open()) {
        while (file >> word) {
            for (char& c : word) {
                if (c >= 'A' && c <= 'Z') {
                    c = tolower(c);
                }
            }
            bst.add(word);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
    
    return bst;
}
