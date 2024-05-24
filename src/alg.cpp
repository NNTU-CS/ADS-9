// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <fstream>
#include "bst.h"

using namespace std;

BST<std::string> makeTree(const char* filename) {
    BST<string> bst;
    ifstream fin(filename);
    string str = "";
    if (fin.is_open()) {
        while (!fin.eof()) {
            str += (char)fin.get();
        }
        fin.close();
    } else {
        cout << "Ошибка";
    }
    string currentWord = "";
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i]) ) {
            if(isupper(str[i])) {
                currentWord += tolower(str[i]);
            } else {
                currentWord += str[i];
            }
        } else {
            if (currentWord != "") {
                bst.add(currentWord);
            }
            currentWord = "";
        }
    }
    if (currentWord != "") {
        bst.add(currentWord);
    }
    return bst;
}
