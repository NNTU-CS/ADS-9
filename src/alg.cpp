// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> MyTree;
  std::ifstream fin(filename);
  char i;
  std::string wd = "";
  if (!fin.is_open()) {
      std::cout << "Error! File can't be open!" << std::endl;
      return MyTree;
  }
  while (!fin.eof()) {
      i = fin.get();
      if (i >= 'A') {
          if (i <= 'Z') {
              i = i + 32;
          }
      }
      if (i >= 'a') {
          if (i <= 'z') {
              wd += i;
          }
      } else {
          MyTree.Add(wd);
          wd = "";
      }
  }
  fin.close();
  return MyTree;
}
