// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;

    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }

    std::string word;
    while (file >> word) {
        // Преобразуем слово в нижний регистр
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Удаляем все нелатинские символы и цифры
        std::string filteredWord;
        for (char c : word) {
            if (isalpha(c)) {
                filteredWord += c;
            }
        }

        if (!filteredWord.empty()) {
            tree.insert(filteredWord);
        }
    }

    file.close();

    return tree;
}
