// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
  if (!file)
    std::cout << "File error!" << std::endl;
  BST<std::string> finalTree;
  std::string currentWordInFile;
  bool flag = true;
  while (!file.eof()) {
    currentWordInFile = "";
    while (flag) {
      char currentSymbol = file.get();
      if (std::isalpha(currentSymbol)) {
        currentWordInFile += std::tolower(currentSymbol);
      } else {
        currentWordInFile = "";
        break;
      }
    }
    if (!currentWordInFile.empty())
      finalTree.add(currentWordInFile);
  }
  file.close();
  return finalTree;
}
