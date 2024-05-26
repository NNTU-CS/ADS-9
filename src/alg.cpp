// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        throw std::string("File not found");
    }

    std::string currentWord = "";
    BST<std::string> binarySearchTree;

    while (inputFile >> currentWord) {
        std::string word = "";
        for (char symbol : currentWord) {
            if ((symbol == 'A' && symbol <= 'Z') || (symbol >= 'a' && symbol <= 'z')) {
                word += tolower(symbol);
            }
        }
        binarySearchTree.AddValue(word);
    }

    return binarySearchTree;
}
