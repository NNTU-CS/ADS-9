// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  <string>
#include  "bst.h"


BST<std::string> makeTree(const char* filename) {
BST<std::string> wordtr;
std::ifstream file(filename);
std::string wrd = "";
if (!file) {
std::cout << "File error!" << std::endl;
return  wordtr;
}
while (!file.eof()) {
char simv = file.get();
if (simv >= 65 && simv <= 90) {
wrd += tolower(simv);
} else if (simv >= 97 && simv <= 122) {
wrd += simv;
} else {
wordtr.add(word);
wrd = "";
}
}
file.close();
return wordtr;
}
