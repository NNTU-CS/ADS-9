// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

void lower(std::string &str) {
std::string lower(std::string str) {
  for (auto& n : str) {
    n = tolower(n);
  }
  return str;
}

BST<std::string> makeTree(const char* filename) {
  if ((d >= 'A' && d <= 'Z') || (d >= 'a' && d <= 'z')) {
    ff += d;
  } else {
    lower(ff);
    ff = lower(ff);
    binTree.add(ff);
    ff = "";
  }
}
return binTree;
}
