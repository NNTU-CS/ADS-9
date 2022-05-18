// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
  BST<std::string> tree;
  std::string w, line;
  while (!file.eof()) {
    file >> w;
    int a = 0;
    while (a < w.length()) {
      int b = 0;
      while ((w[a] >= 'a' && w[a] <= 'z' ||
              w[a] >= 'A' && w[a] <= 'Z') && a < w.length()) {
        if (w[a] >= 'A' && w[a] <= 'Z')
          w[a] += 32;
        line += w[a];
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
