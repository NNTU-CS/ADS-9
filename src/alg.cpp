// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
      std::ifstream fin(filename);
    if (!fin) {
        exit(1);
    }
    BST<std::string> t;
    while (!fin.eof()) {
        char ch;
        std::string str;
        fin.get(ch);
        if (isalpha(ch))
            str += tolower(ch);
        else if (!str.empty())
            t.add(str);
    }
    fin.close();
    return t;
}
