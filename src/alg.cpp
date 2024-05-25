// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char *filename) {
  BST<std::string> tree;
  std::fstream input(filename);
  std::string result = "";
  char next;

  while (input) {
    next = input.get();
    if (isalpha(next)) {
      next = tolower(next);
      result += next;
    } else if (!(result.empty())) {
      tree.add(result);
      result = "";
    }
  }

  if (!(result.empty())) tree.add(result);

  input.close();

  return tree;
}
