// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  std::ifstream file(filename);
  BST<std::string> tree;
  std::string word, line;
  while (!file.eof()) {
    file >> word;
    int i = 0;
    while (i < word.length()) {
      int k = 0;
      while ((word[i] >= 'a' && word[i] <= 'z' ||
              word[i] >= 'A' && word[i] <= 'Z') && i < word.length()) {
        if (word[i] >= 'A' && word[i] <= 'Z')
          word[i] += 32;
        line += word[i];
        k++;
        i++;
      }
      if (k != 0) {
        tree.add(line);
        line = "";
      } else {
        i++;
      }
    }
  }
  return tree;
}
