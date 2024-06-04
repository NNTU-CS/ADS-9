// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  BST<std::string> Tree;
  std::ifstream file(filename);
  std::string strfl = "";
  if (!file) {
    std::cout << "Error!" << std::endl;
    return Tree;
  }
  while (!file.eof()) {
    char x = file.get();
    strfl += x;
  }
  for (char& n : strfl) {
    n = std::tolower(n);
  }
  int length = strfl.length();
  bool wrd = false;
  std::string tmp = "";
  for (int i = 0; i < length; i++) {
    if (strfl[i] >= 'a' && strfl[i] <= 'z') {
      wrd = true;
    } else {
      wrd = false;
    }
    if (wrd) {
      tmp += strfl[i];
    } else {
      Tree.add(tmp);
      tmp = "";
    }
  }
  file.close();
  return Tree;
}
