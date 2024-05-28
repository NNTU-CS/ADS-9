// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

std::unordered_map<std::string, int> buildWordFrequencyMap(const char* filename) {
  std::unordered_map<std::string, int> wordFrequencyMap;
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error opening file!" << std::endl;
    return wordFrequencyMap;
  }
  std::string word;
  while (file >> word) {
    word.erase(std::remove_if(word.begin(), word.end(), [](unsigned char c) { return !std::isalpha(c); }), word.end());
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    wordFrequencyMap[word]++;
  }
  file.close();
  return wordFrequencyMap;
}
