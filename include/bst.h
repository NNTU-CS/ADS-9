// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

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

    int BranchSeek(List* host, T desired) {
        if (host == nullptr) {
            return 0;
        }
        if (host->bstword == desired) {
            return host->score;
        } else if (host->bstword > desired) {
            return BranchSeek(host->Lside, desired);
        } else {
            return BranchSeek(host->Rside, desired);
        }
    }

    int knowDepth(List* host) {
        if (host == nullptr) {
            return 0;
        }
        int rbranch = knowDepth(host->Rside);
        int lbranch = knowDepth(host->Lside);
        return 1 + std::max(rbranch, lbranch);
    }

 public:
    BST() : host(nullptr), todepth(0) {}

    List*& gethost() {
        return host;
    }

    void ListAd(List*& host, T speak) {
        if (host == nullptr) {
            host = new List;
            host->Lside = nullptr;
            host->Rside = nullptr;
            host->score = 1;
            host->bstword = speak;
        } else if (host->bstword < speak) {
            ListAd(host->Rside, speak);
        } else if (host->bstword > speak) {
            ListAd(host->Lside, speak);
        } else {
            host->score = 1 + host->score;
        }
    }

    int search(T desired) {
        return BranchSeek(host, desired);
    }

    int depth() {
        return (-1) + knowDepth(host);
    }
};

#endif  // INCLUDE_BST_H_
