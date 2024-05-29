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
string word;
char chu;
BST<string> Tree;
if (!file) {
  cout << "File error!" << endl;
}
while (file.get(chu)) {
  if (isalpha(chu)) {
    word += tolower(chu);
  }
  else {
    Tree.addNew(word);
    word.clear();
  }
}
file.close();
return Tree;
}
