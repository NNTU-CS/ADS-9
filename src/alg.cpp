// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
    std::ifstream file(filename);
    std::string line, word;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            while (iss >> word) {
                std::string lowercaseWord;
                for (char c : word) {
                    if (std::isalpha(c) && std::islower(c)) {
                        lowercaseWord += c;
                    }
                }
                if (!lowercaseWord.empty()) {
                    tree.insert(lowercaseWord);
                }
            }
        }
        file.close();
    }
  return tree;
}
