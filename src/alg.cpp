// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return tree;
    }

    std::string word;
    while (file >> word) {
        // Преобразуем слово в нижний регистр
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Оставляем только последовательности латинских букв
        word.erase(std::remove_if(word.begin(), word.end(), [](char c) {
            return !std::isalpha(c);
        }), word.end());

        // Добавляем слово в дерево
        if (!word.empty()) {
            tree.add(word);
        }
    }

    file.close();
    return tree;
}

int main() {
    const char* filename = "war_peace.txt";
    BST<std::string> tree = makeTree(filename);

    std::cout << "Depth of the tree: " << tree.depth() << std::endl;

    std::cout << "Word frequencies:" << std::endl;
    std::string mostFrequentWord;
    int maxCount = 0;
    while (!mostFrequentWord.empty()) {
        tree.findMostFrequent(mostFrequentWord, maxCount);
        if (!mostFrequentWord.empty()) {
            std::cout << mostFrequentWord << ": " << maxCount << std::endl;
            tree.remove(mostFrequentWord);
        }
    }

    return 0;
}
