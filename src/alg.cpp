// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> MyTree;
  std::ifstream fin(filename);
  char J;
  std::string word = "";
  if (!fin.is_open()) {
      std::cout << "Error! File can't be open!" << std::endl;
      return MyTree;
  }
  while (!fin.eof()) {
      J = fin.get();
      if (J >= 'A') {
          if (J <= 'Z') {
              J = J + 32;
          }
      }
      if (J >= 'a') {
          if (J <= 'z') {
              word = word + J;
          }
      } else {
          MyTree.Add(word);
          word = "";
      }
  }
  fin.close();
  return MyTree;
}
