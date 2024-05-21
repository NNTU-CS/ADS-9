// Copyright 2021 NNTU-CS
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
    std::ifstream file(filename);
    BST<std::string> tree;
    std::string word;
    while (!file.eof()) {
        char ch = file.get();
        if (ch != ' ' && isalpha(ch)) {
            ch = tolower(ch);
            word += ch;
        } else {
            tree.insert(word);
            word.clear();
        }
    }
    return tree;
}
