// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> derevo;
    std::string slovo = "";
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return derevo;
    }
    while (!file.eof()) {
        char sym = file.get();
        if ((sym >= 'a' && sym <= 'z') || (sym >= 'A' && sym <= 'Z')) {
            slovo += tolower(sym);
        } else if (slovo != "") {
            derevo.add(slovo);
            slovo = "";
        }
    }
    file.close();
    return derevo;
}
