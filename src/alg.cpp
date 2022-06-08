// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  std::ifstream file(filename);
  BST<std::string> derevo;
  std::string lier;
  std::string slovo;
  while (!file.eof()) {
  file >> slovo;
  int i = 0;
  while (i < slovo.length()) {
  int j = 0;
  while ((slovo[i] >= 'a' && slovo[i] <= 'z' || slovo[i] >= 'A' && slovo[i] <= 'Z') && i < slovo.length()) {
  if (slovo[i] >= 'A' && slovo[i] <= 'Z')
  slovo[i] += 32;
  lier += slovo[i];
  i++;
  j++;
  }
  if (j != 0) {
  derevo.add(lier);
  lier = "";
  } else {
  i++;
  }
  }
  }
  return derevo;
}
