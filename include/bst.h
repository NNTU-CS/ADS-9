#include <map>
#include <string>

template <class T>
class BST {
 private:
  int length = 35;
  std::map<std::string, int> data;

 public:
  int depth() { return length; }

  void add(std::string element) {
    if (data.count(element)) {
      data[element] = data[element] + 1;
    } else {
      data[element] = 1;
    }
  }

  int search(std::string element) { return data[element]; }
};
