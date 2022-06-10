// Copyright 2021 CheginArtyom
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makevetki(const char* filename) {
  BST<std::string> vetki;
  std::ifstream file(filename);
  char t;
  std::string slovo = "";
    if (!file.is_open()) {
        std::cout << "File error!" << std::endl;
        return vetki;
    }
    while (!file.eof()) {
      t = file.get();
      if ((t >= 'A') && (t <= 'Z'))
        t += 32;
      if ((t >= 'a') && (t <= 'z')) {
        slovo += t;
      } else {
        vetki.Plus(slovo);
        slovo = "";
      }
    }
    file.close();
  return vetki;
}
