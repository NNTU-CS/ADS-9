// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <vector>

#include  "bst.h"

BST<std::string> makeTree(const char *filename) {
   #include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <vector>
#include  "bst.h"
BST<std::string> makeTree(const char *filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error!" << std::endl;
    }
    BST<std::string> tree;
    char ch;
    char *sl = new char;
    int counter = 0;
    std::string stroka;
    std::vector<std::string> txt;
    while (!file.eof()) {
        file.get(ch);
        if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123)) {
            sl[counter] = tolower(ch);
            counter++;
        } else {
            for (int i = 0; i < counter; i++) {
                stroka += sl[i];
            }
            if (stroka != "") {
                txt.push_back(stroka);
            }
            stroka = "";
            counter = 0;
        }
    }
    for (int i = text.size; i > 0; i--) {
        tree.add(text[i]);
        text.pop_back();
    }
    file.close();
    return tree;
}
