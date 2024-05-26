// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> BSTtree; // Создание пустого бинарного дерева поиска для строк
  std::ifstream file(filename); // Открытие файла для чтения
  std::string res; // Переменная для хранения текущего слова
  while (!file.eof()) { // Цикл, читающий файл до его конца
      char c = file.get(); // Чтение символа из файла
      if (c >= 'A' && c <= 'Z') // Если символ - заглавная буква
          c = c + ('a' - 'A'); // Преобразование в строчную букву
      if (c >= 'a' && c <= 'z') { // Если символ - строчная буква
          res += c; // Добавление символа к текущему слову
      } else { // Если символ не является буквой
          BSTtree.insert(res); // Добавление слова в бинарное дерево поиска
          res.clear(); // Очистка текущего слова для следующей итерации
      }
  }
  return BSTtree; // Возврат заполненного бинарного дерева поиска
}
