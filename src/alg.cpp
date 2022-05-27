// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> Drevo;
  std::ifstream fin(filename);
  char tempr;
  std::string word = "";
  if (!fin.is_open()) {
      std::cout << "Error! File can't be open!" << std::endl;
      return Drevo;
  }
  while (!fin.eof()) {
      tempr = fin.get();
      if (tempr >= 'A') {
          if (tempr <= 'Z') {
              tempr = tempr + 32;
          }
      }
      if (tempr >= 'a') {
          if (tempr <= 'z') {
              word = word + tempr;
          }
      } else {
          Drevo.Add(word);
          word = "";
      }
  }
  fin.close();
  return Drevo;
}
