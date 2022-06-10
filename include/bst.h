// Copyright 2021 CheginArtyom
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template<typename T>
class BST {
 public:
  BST() :kor(nullptr) {}
    void Plus(const T& znc) {
    kor = plusvetka(kor, znc);
    }
    int poisk(const T& znc) {
    return poiskvetka(kor, znc);
  }
  int d() {
    return dp(kor) - 1;
  }

 private:
  struct vetka {
    T zn;
    int c = 0;
    vetka* levo = nullptr;
    vetka* pravo = nullptr;;
  };
    vetka* kor;
    vetka* plusvetka(vetka* kor, const T& znc) {
    if (kor == nullptr) {
      kor = new vetka;
      kor->zn = znc;
      kor->c = 1;
      kor->levo = kor->pravo = nullptr;
  } else if (kor->zn < znc) {
      kor->levo = plusvetka(kor->levo, znc);
    } else if (kor->zn > znc) {
        kor->pravo = plusvetka(kor->pravo, znc);
      } else {
          kor->c++;
        }
    return kor;
    }
    int poiskvetka(vetka* kor, const T& znc) {
      if (kor == nullptr) {
        return 0;
      } else if (kor->zn == znc) {
          return kor->c;
        } else if (kor->zn < znc) {
            return poiskvetka(kor->levo, znc);
          } else {
              return poiskvetka(kor->pravo, znc);
            }
    }
    int dp(vetka* kor) {
      int lft = 0, rht = 0;
      if (kor == nullptr) {
        return 0;
      } else {
          lft = dp(kor->levo);
          rht = dp(kor->pravo);
        }
        if (rht > lft) {
            return ++rht;
        } else {
            return ++lft;
          }
    }
};
#endif  // INCLUDE_BST_H_
