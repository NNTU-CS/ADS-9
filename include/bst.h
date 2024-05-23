// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
BST<std::string> makeTree (const char* filename) {
    BST <std::string> storage;
    std::ifstream file(filename);
    if (!file) {
        std::cout << "File error!" << std::endl;
        return;
    }
        int count = 0;
        std::string str;
        bool inString = false;
    while (!file.eof()) {
        int ch = file.get();
        if (ch >= 'A' && ch <= 'Z') {
            inString = true;
            ch = tolower(ch);
            str += ch;
        } else if (ch >= 'a' && ch <= 'z') {
            inString = true;
            str += ch;
        } else if (inString) {
            storage.add(str);
            str.clear();
        }
    }
    file.close();
    return storage;
}
#endif  // INCLUDE_BST_H_
