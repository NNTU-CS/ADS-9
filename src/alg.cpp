// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <sstream>
#include  <cctype>
#include  <algorithm>
#include  <string>
#include  "bst.h"

std::string cleanText(std::string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    text.erase(remove_if(text.begin(), text.end(), ::ispunct), text.end());
    return text;
}
BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
    std::ifstream file(filename);
    if (!file.is_open()) {
      std::cerr << "Ошибка открытия файла: " << filename << std::endl;
      exit(1);
    }
    BST<std::string> tree;
    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(cleanText(line));
        std::string word;
        while (ss >> word) {
            tree.insert(word);
        }
    }
    file.close();
    return tree;
}
