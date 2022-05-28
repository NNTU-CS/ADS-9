// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <cctype>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::string b = "";
  char a;
  std::ifstream file(filename);
  while (!file.eof()) {
    a = file.get();
    if ((a != '.') && (a != ',') && (a != '!') &&
(a != '?') && (a != ';') && (a != ':') &&
(a != '"') && (a != '\'') && (a != '/') &&
(a != '-') && (a != '[') && (a != ']') &&
(a != '(') && (a != ')') && (a != '*') &&
(a != '0') && (a != '1') && (a != '2') &&
(a != '3') && (a != '4') && (a != '5') &&
(a != '6') && (a != '7') && (a != '8') &&
(a != '9') && (a != ' ') && (a != '\n')) {
      a = tolower(a);
      b += a;
    } else {
      if (b != "") {
        tree.add(b);
        b = "";
      }
    }
  }
  file.close();
  return tree;
}
