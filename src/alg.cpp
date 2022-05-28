// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> BSTree;
  std::ifstream glav(filename);
  std::string word = "";
  if (!glav) throw std::string("Where is your file?");
  while (!glav.eof()) { //eof возвращает значение 1, если текущая точка — конец файла, или значение 0, если это не так
    char simb = glav.get();
    if ((simb >= 'A' && simb <= 'Z') || (simb >= 'a' && simb <= 'z')) {
      word += tolower(simb); //выполняет преобразование прописных букв в строчные
    } else {
      BSTree.add(word);
      word = "";
    }
  }
  glav.close();
  return BSTree;
}
