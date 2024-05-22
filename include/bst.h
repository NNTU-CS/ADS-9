// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <algorithm>
#include <map>
#include <string>
template <typename T>
class BST {
 private:
    std::map<std::string, int> data;

 public:
        int depth() { return data.size(); }

    void add(std::string element) {
        std::transform(element.begin(), element.end(), element.begin(), ::tolower); // Приводим к нижнему регистру
        element.erase(remove_if(element.begin(), element.end(), ::ispunct), element.end()); // Удаляем знаки препинания
        if (data.count(element)) {
            data[element]++;
        } else {
            data[element] = 1;
        }
    }

    int search(std::string element) {
        std::transform(element.begin(), element.end(), element.begin(), ::tolower); // Приводим к нижнему регистру
        element.erase(remove_if(element.begin(), element.end(), ::ispunct), element.end()); // Удаляем знаки препинания
        if (data.count(element)) {
            return data[element];
        } else {
            return 0; // Или любое другое значение, которое вы хотите вернуть в случае отсутствия элемента
        }
    }

    void printTree() {
        for (const auto& pair : data) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }
};
#endif  // INCLUDE_BST_H_
