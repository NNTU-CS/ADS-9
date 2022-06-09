// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
    std::ifstream file(filename);
    std::string word, temp;

    while (!file.eof()) {
        file >> word;
        int i = 0;
        while (i < word.length()) {
            int k = 0;
            while ((word[i] >= 'a' && word[i] <= 'z' || word[i] >= 'A' && word[i] <= 'Z') && i < word.length()) {
                if (word[i] >= 'A' && word[i] <= 'Z') {
                    word[i] = word[i] + 32;
                }
                temp = temp + word[i];
                k++; i++;
            }
            if (k != 0) {
                tree.add(temp);
                temp = "";
            } else {
                i++;
            }
        }
    }
    return tree;
}
