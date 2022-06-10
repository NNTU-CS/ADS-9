// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> vetki;
  std::ifstream file(filename);
  char t;
  std::string slovo = "";
  if (!file.is_open()) {
      std::cout << "Error!" << std::endl;
      return vetki;
  }
  while (!file.eof()) {
      t = file.get();
      if (t >= 'A') {
          if (t <= 'Z') {
              t += 32;
          }
      }
      if (t >= 'a') {
          if (t <= 'z') {
              slovo += t;
          }
      } else {
          vetki.Add(slovo);
          slovo = "";
      }
  }
  file.close();
  return vetki;
}
