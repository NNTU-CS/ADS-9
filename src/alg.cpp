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
  std::ifstream file(filename);
  BST<std::string> finalTree;
  std::string currentWordInFile;
  while (!file.eof()) {
    char currentSymbol = file.get();
    if (currentSymbol >= 'A' && currentSymbol <= 'Z') {
      currentWordInFile.append(1, currentSymbol);
    } else if (currentWordInFile.size() != 0) {
      finalTree.addValue(currentWordInFile);
      currentWordInFile.clear();
    }
  }
  while (currentWordInFile.size() != 0)
    finalTree.addValue(currentWordInFile);
  return finalTree;
}
