// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
 std::ifstream file(filename);
std::string word;
char chu;
BST<std::string> Tree;
if (!file) {
  std::cout << "File error!" << std::endl;
}
while (file.get(chu)) {
  if (isalpha(chu)) {
    word += tolower(chu);
  } else {
    Tree.addNew(word);
    word.clear();
  }
}
file.close();
return Tree;
}
