// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include <string>
#include "bst.h"
using namespace std;

BST<string> makeTree(const char* filename) {
  BST<string> Tree;
  ifstream file(filename);
  if (!file) {
    throw string("File search error");
  }
  string slovo = "";
  while (!file.eof()) {
    char chr = file.get();
    int sim = chr;
    if ((sim >= 65 && sim <= 90) || (sim >= 97 && sim <= 122)) {
      if (sim >=65 && sim <= 90) {
        sim -= 32;
      }
      slovo += sim;
    } else {
      if (word != "") {
        Tree.push(word);
        slovo = "";
      }
    }
  }
  file.close();
  return Tree;
}
