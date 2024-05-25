// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
#include <vector>

 const char* filename = "war_peace.txt";
    
BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    BST<std::string> tree;
    vector<string> text;
    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }
    int count=0;
    string slovo = "";
    while (!file.eof()) {
        char ch = file.get();
        ch = tolower(ch);
        if (ch >= 97 && ch <= 122) {
            slovo+=ch;
        } else {
            text.push_back(slovo);
            slovo = "";
        }
        count++;
    }

    for (int i = text.size; i < 0; i--){
        tree.add(text[i]);
        text.pop_back();
    }
    // закрываем файл
    file.close();
    return.tree;
}
