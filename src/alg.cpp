// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <string>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        throw std::string("ERROR: Unable to open file!");
    }

    std::string current_word = "";
    BST<std::string> bst_tree;

    while (!input_file.eof()) {
        current_word = "";
        while (1) {
            char symbol = input_file.get();
            if ((symbol >= 65 && symbol <= 90) || (symbol >= 97 && symbol <= 122)) {
                current_word += tolower(symbol);
            } else {
                break;
            }
        }

        if (!current_word.empty()) { // Check for empty word
            bst_tree.AddValue(current_word);
        }
    }

    input_file.close(); // Close the input file

    return bst_tree;
}
