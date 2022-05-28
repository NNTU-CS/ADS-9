// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> derevo;
  std::ifstream fin(filename);
  char t;
  std::string word = "";
  if (!fin.is_open()) {
      std::cout << "Error! File can't be open!" << std::endl;
      return derevo;
  }
  while (!fin.eof()) {
      t = fin.get();
      if (t >= 'A') {
          if (t <= 'Z') {
              t = t + 32;
          }
      }
      if (t >= 'a') {
          if (t <= 'z') {
              word = word + t;
          }
      } else {
          derevo.Add(word);
          word = "";
      }
  }
  fin.close();
  return derevo;
}
