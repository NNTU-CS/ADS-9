// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::string Word;
  std::ifstream File(filename);
  if (!File.is_open()) {
    throw std::string("Error");
  }
  while (File) {
    char Letter = File.get();
    if (isalpha(Letter)) {
      Letter = tolower(Letter);
      Word += Letter;
    } else if (!Word.empty()) {
      tree.add(Word);
      Word.clear();
    }
  }
  if (!Word.empty()) {
    tree.add(Word);
  }
  File.close();
  return tree;
}
