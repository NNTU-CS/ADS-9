// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
  BST<std::string> tree;
  std::string word, line;
  while (!file.eof()) {
    file >> word;
    int a = 0;
    while (a < word.length()) {
      int b = 0;
      while ((word[a] >= 'a' && word[a] <= 'z' ||
              word[a] >= 'A' && word[a] <= 'Z') && a < word.length()) {
        if (word[a] >= 'A' && word[a] <= 'Z')
          word[a] += 32;
        line += word[a];
        b++;
        a++;
      }
      if (b != 0) {
        tree.add(line);
        line = "";
      } else {
        a++;
      }
    }
  }
  return tree;
}
