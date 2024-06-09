// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> WarPeaсeTree;
  std::ifstream file(filename);
  std::string Word;
  char Token;
  while (!file.eof()) {
    Token = file.get();
    Token = LowercaseTranslation(Token);
    if (Token >= 'a' && Token <= 'z') {
      Word += Token;
    } else {
      WarPeaсeTree.add(Word);
      Word.clear();
    }
  }
  return WarPeaсeTree;
}

char LowercaseTranslation(char Token) {
  if (Token >= 'A' && Token <= 'Z') {
    Token = Token + ('a' - 'A');
  }
  return Token;
}
