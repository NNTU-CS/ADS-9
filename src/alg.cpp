// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
using namespace std;

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
  ifstream file(filename);
  if (!file) {
    cout << "File error!" << endl;
  }
  string word;
  char s;
  BST<string> three;
  while (file.get(s)) {
    if (isalpha(s)) {
      word += tolower(s);
    }
    else {
      three.addNew(word);
      word.clear();
    }
  }
  file.close();
  return three;
}
