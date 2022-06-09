// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> Tree;
  std::string word = "";
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return Tree;
  }
  while (!file.eof()) {
    char chan = file.get();
    if ((chan >= 'A' && chan <= 'Z') || (chan >= 'a' && chan <= 'z')) {
      if (chan >= 'A' && chan <= 'Z')
        chan = tolower(chan);
      word += chan;
    } else {
      Tree.add(word);
      word = "";
    }
  }
  file.close();
  return Tree;
}
