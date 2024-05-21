// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#define EX(cont) if (cont == nullptr) { return 0; };
#include <algorithm>
#include <string>

struct List {
    List* Lside;
    List* Rside;
    int score;
    std::string bstword;
};

template<typename T>
class BST {
 private:
    List* host;
    int todepth;

    int knowDepth(List* host) {
        EX(host);
        int rbranch = knowDepth(host->Rside);
        int lbranch = knowDepth(host->Lside);
        return 1 + std::max(rbranch, lbranch);
    }

    int BranchSeek(List* host, T desired) {
        EX(host);
        if (host->bstword == desired) {
            return host->score;
        } else if (host->bstword > desired) {
            return BranchSeek(host->Lside, desired);
        } else {
            return BranchSeek(host->Rside, desired);
        }
    }

 public:
    BST() : host(nullptr), todepth(0) {}

    List** gethost() {
        return &host;
    }

    List* ListAd(List** host, T speak) {
        if ((*host) == nullptr) {
            (*host) = new List;
            (*host)->Lside = nullptr;
            (*host)->Rside = nullptr;
            (*host)->score = 1;
            (*host)->bstword = speak;
        } else if ((*host)->bstword < speak) {
            (*host)->Rside = \
                ListAd(&((*host)->Rside), speak);
        } else if ((*host)->bstword > speak) {
            (*host)->Lside = \
                ListAd(&((*host)->Lside), speak);
        } else {
            (*host)->score = 1 + (*host)->score;
        }
        return (*host);
    }

    int depth() {
        return (-1) + knowDepth(host);
    }
    int search(T speak) {
        return BranchSeek(host, speak);
    }
};

#endif  // INCLUDE_BST_H_
