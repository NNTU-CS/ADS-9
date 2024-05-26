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
  boolean flag = true;
  while (!file.eof()) {
    currentWordInFile = "";
    while (flag) {
      char currentSymbol = file.get();
      if (std::isalpha(currentSymbol)) {
        currentWordInFile += std::tolower(currentSymbol);
      } else if (currentWordInFile.size() != 0) {
        finalTree.add(currentWordInFile);
        currentWordInFile = "";
      }
    }
    if (currentWordInFile.size() != 0)
    finalTree.add(currentWordInFile);
  }
  return finalTree;
}
