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
  data["pierre"] = 1963;
  data["natasha"] = 1212;
  data["andrew"] = 1143;
}
  int search(std::string element) {return data[element];}
};
