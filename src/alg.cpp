// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::ifstream text(filename);
  BST<std::string> newTree;
  std::string slova = "";
  char raznic = 'a' - 'A';
  if (!text) {
    std::cout << "File is not found" << std::endl;
    return newTree;
  }
  while (!text.eof()) {
    char sim = text.get();
    if (sim >= 'A' && sim <= 'Z') {
      sim = sim + raznic;
      slova = slova + sim;
    } else if (('z' >= sim) && ('a' <= sim)) {
      slova = slova + sim;
    } else {
      newTree.add(slova);
      slova = "";
    }
  }
  text.close();
  return newTree;
}
