// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> Ttree;
    std::ifstream file(filename);

    if (!file) {
        std::cout << "Ошибка" << std::endl;
        return Ttree;
    }
    char Bukv;
    std::string slov = "";
    while (!file.eof()) {
        Bukv = file.get();
        if ((Bukv >= 65 && Bukv <= 90) || (Bukv >= 97 && Bukv <= 122)) {
            slov += tolower(Bukv);
        } else {
            Ttree.add(slov);
            slov = "";
        }
    }
    file.close();
    return Ttree;
}
