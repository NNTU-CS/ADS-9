// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    BST<std::string> tree;
    std::string speak = "";
    char sym;
    
    while (!file.eof()) {
        sym = file.get();
        if (!(sym > 'Z' && sym < 'a') && \
            (sym >= 'A' && sym <= 'z')) {
            if (sym <= 'Z') {
                sym += 32;
            }
            speak.append(1, sym);
        } else {
            if (!speak.empty()) {
                List** adr = tree.gethost();
                tree.ListAd(adr, speak);
                speak.clear();
            }
        }
    }
    file.close();
    return tree;
}
