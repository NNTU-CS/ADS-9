// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

void lower(std::string str) {
std::string lower(std::string str) {
  for (auto& n : str) {
    n = tolower(n);
  }
  return str;
}

BST<std::string> makeTree(const char* filename) {
  BST<std::string> der;
  std::ifstream mr(filename);
  std::string w = "";
  while (!mr.eof()) {
    char d = mr.get();
    if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z')) {
      ff = ff + d;
    } else {
      lower(ff);
      ff = lower(ff);
      der.add(ff);
      ff = "";
    }
  }
  return der;
}
