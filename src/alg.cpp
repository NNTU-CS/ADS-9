// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
    BST<std::string> Tree;
    std::string symb = "";
    // если файл не открылся, прекращаем работу
    if (!file) {
        throw std::string("File not found");
    }
    // читаем содержимое файла посимвольно
    while (!file.eof()) {
        symb = "";
        while (true) {
            char c = file.get();
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
                symb += tolower(c);
            else
                break;
        }
        Tree.add(symb);
    }
    return Tree;
    // закрываем файл
    file.close();
}
