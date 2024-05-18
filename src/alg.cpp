// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> Mytree;
    std::ifstream file(filename);
    std::string s;
    std::string s1 = "";
    std::string s2 = "";
    while (!file.eof()) {
        file >> s;
        s1 = s2 = "";
        if (s.find(",") != -1) {
                int len = s.length();
                int fin = s.find(",");
                if ((fin != len - 1) && ((s[fin + 1] >= 'A' && s[fin + 1] <= 'Z') ||
                    (s[fin + 1] >= 'A' && s[fin + 1] <= 'z'))) {
                for (int i = 0; i < fin; i++) {
                    s1 += s[i];
                }
                for (int i = fin+1; i < len; i++) {
                    s2 += s[i];
                }
            }
        }
        if (s1 != "" && s2 != "") {
            s1 = get_corr_word(s1);
            s2 = get_corr_word(s2);
            Mytree.add(s1);
            Mytree.add(s2);
        } else {
            s = get_corr_word(s);
            Mytree.add(s);
        }
    }
    return Mytree;
}

std::string get_corr_word(std::string a) {
    if (a[0] < '0' || a[0] > '9') {
        while ((a[0] >= 32 && a[0] <= 64) || (a[0] >= 91 && a[0] <= 96))
        a.erase(0, 1);
        if (a != "") {
            char ch = a[a.length() - 1];
            while ((ch >= 32 && ch <= 64) || (ch >= 91 && ch <= 96)) {
                a.pop_back();
                ch = a[a.length() - 1];
            }
        }
        int r = 0;
        if (a != "") {
            for (int i = 0; i < a.length(); i++) {
                if (a[i] == '\'') {
                    r = i;
                }
            }
            if (r != 0)
                a.erase(r);
        }
        if (a != "") {
            for (int i = 0; i < a.length(); i++) {
                a[i] = tolower(a[i]);
            }
        }
    } else {
        a.clear();
    }
    return a;
}
