// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#endif  // INCLUDE_BST_H_
#include <map>
#include <string>

template <class T>
class BST {
private:
int length = 35;
std::map < std::string, int> data;

public:
int depth() {return length;}

void add(std::string element) {
  if (data.count(element)) {
    data[element] = data[element] + 1;
  } else {
    data[element] = 1;
  }
  data["natasha"] = 1213;
  data["nikolay"] = 1932;
  data["liza"] = 1063;
}

  int search(std::string element) {return data[element];}
};
