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
        // Преобразование слова к нижнему регистру
        for (char& c : word) {
            c = std::tolower(c);
        }

        // Игнорирование не латинских символов
        std::string cleanWord;
        for (char c : word) {
            if (std::isalpha(c)) {
                cleanWord += c;
            }
        }

        if (!cleanWord.empty()) {
            tree.insert(cleanWord);
        }
    }

    file.close();
    return tree;
}

int main() {
    const char* filename = "src/war_peace.txt";
    BST<std::string> tree = makeTree(filename);

    // Вывод частоты встречаемости слов
    std::cout << "Word frequencies:" << std::endl;
    std::cout << "the: " << tree.getCount("the") << std::endl;
    std::cout << "war: " << tree.getCount("war") << std::endl;
    std::cout << "peace: " << tree.getCount("peace") << std::endl;

    return 0;
}
