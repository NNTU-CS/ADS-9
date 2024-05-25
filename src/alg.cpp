// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  "bst.h"
#include <sstream>
#include <regex>

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::ifstream file(filename);

  if (!file.is_open()) {
      throw std::runtime_error("Ошибка открытия файла");
  }

  std::stringstream buffer;
  buffer << file.rdbuf();
  file.close();

  std::string content = buffer.str();
  std::regex wordRegex("[a-zA-Z]+");
  std::smatch match;

  while (std::regex_search(content, match, wordRegex)) {
      std::string word = match.str();
      std::transform(word.begin(), word.end(), word.begin(), ::tolower);
      tree.insert(word);
      content = match.suffix();
  }
  return tree;
}
