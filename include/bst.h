// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
template <typename T>
class BST {
 private:
    std::map<std::string, int> data;

 public:
    int depth() { return data.size(); }

    void add(std::string element) {
        if (data.count(element)) {
            data[element]++;
        } else {
            data[element] = 1;
        }
    }

    int search(std::string element) {
        if (data.count(element)) {
            return data[element];
        } else {
            return 0;
        }
    }

    void printTree() {
        for (const auto& pair : data) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }
};
#endif  // INCLUDE_BST_H_
