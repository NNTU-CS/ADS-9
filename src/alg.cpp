// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
#include <vector>

BST<std::string> makeTree(const char* filename) {
 std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
    }
    BST<std::string> tree;
    char ch;
    char* arr = new char;
    int counter = 0;
    std::string stroka;
    std::vector<std::string> vec;
    while (!file.eof()) {
        file.get(ch);
        if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123)) {
            arr[counter] = tolower(ch);
            counter++;
        } else {
            for (int i = 0; i < counter; i++) {
                stroka += arr[i];
            }
            if (stroka != "") {
                vec.push_back(stroka);
            }
            stroka = "";
            counter = 0;
        }
    }
    while (!vec.empty()) {
        tree.add(vec.back());
        vec.pop_back();
    }
    file.close();
    return tree;
}
