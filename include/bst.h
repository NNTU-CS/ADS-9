// Copyright 2021 CheginArtyom
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template<typename T>
class BST {
 public:
  BST() :coordinate(nullptr) {}
    void Plus(const T& constZaza) {
    coordinate = plusvetka(coordinate, constZaza);
    }
    int poisk(const T& constZaza) {
    return serchBreanch(coordinate, constZaza);
  }
  int d() {
    return dp(coordinate) - 1;
  }

 private:
  struct brench {
    T zn;
    int c = 0;
    brench* left = nullptr;
    brench* right = nullptr;;
  };
    brench* coordinate;
    brench* plusvetka(brench* coordinate, const T& constZaza) {
    if (coordinate == nullptr) {
      coordinate = new brench;
      coordinate->zn = constZaza;
      coordinate->c = 1;
      coordinate->left = coordinate->right = nullptr;
  } else if (coordinate->zn < constZaza) {
      coordinate->left = plusvetka(coordinate->left, constZaza);
    } else if (coordinate->zn > constZaza) {
        coordinate->right = plusvetka(coordinate->right, constZaza);
      } else {
          coordinate->c++;
        }
    return coordinate;
    }
    int serchBreanch(brench* coordinate, const T& constZaza) {
      if (coordinate == nullptr) {
        return 0;
      } else if (coordinate->zn < constZaza) {
          return serchBreanch(coordinate->left, constZaza);
        } else if (coordinate->zn == constZaza) {
            return coordinate->c;
          } else {
              return serchBreanch(coordinate->right, constZaza);
            }
    }
    int dp(brench* coordinate) {
      int leftCount = 0, rightCoun = 0;
      if (coordinate == nullptr) {
        return 0;
      } else {
          leftCount = dp(coordinate->left);
          rightCoun = dp(coordinate->right);
        }
        if (rightCoun > leftCount) {
            return ++rightCoun;
        } else {
            return ++leftCount;
          }
    }
};
#endif  // INCLUDE_BST_H_