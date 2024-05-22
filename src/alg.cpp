// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
    BST<std::string> q;
    std::string str;
    char sim;
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return q;
    }
    while (!file.eof())
    {
        sim = file.get();
        if (('a' <= sim) && (sim <= 'z') || ('A' <= sim) && (sim <= 'Z')) {
            str += sim;
        } else {
            if (str.size() != 0) {
                q.add(str);
                str.clear();
            }
        }
    }
    file.close();
    return q;
}
