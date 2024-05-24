// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
using namespace std;

BST<std::string> makeTree(const char* filename) {
      ifstream fin(filename);
    if (!fin) {
        exit(1);
    }
    BST<string> t;
    while (!fin.eof()) {
        char ch;
        string str;
        fin.get(ch);
        if (isalpha(ch))
            str += tolower(ch);
        else if (!str.empty())
            t.add(str);
    }
    fin.close();
    return t;
}
