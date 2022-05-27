// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> MyTree;
  std::ifstream fin(filename);
  char temp;
  std::string word = "";
  if (!fin.is_open()) {
      std::cout << "Error! File can't be open!" << std::endl;
      return MyTree;
  }
  while (!fin.eof()) {
      temp = fin.get();
      if (temp >= 'A') {
          if (temp <= 'Z') {
              temp = temp + 32;
          }
      }
      if (temp >= 'a') {
          if (temp <= 'z') {
              word = word + temp;
          }
      } else {
          MyTree.Add(word);
          word = "";
      }
  }
  fin.close();
  return MyTree;
}
