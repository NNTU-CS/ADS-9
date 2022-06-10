// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    BST<std::string> bst;
    std::string wrd = "";
    int c;
// читаем содержимое файла посимвольно
    while (!file.eof()) {
        char sym = file.get();
        if ((sym >= 'a' && sym <= 'z') || (sym >= 'A' && sym <= 'Z')) {
            if (sym >= 'A' && sym <= 'Z')
                sym += 32;
            wrd += sym;
            c++;
        } else if (c != 0) {
        bst.add(wrd); wrd = "";  c = 0;
        }
    }
    file.close();
    return bst;
}
