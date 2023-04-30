#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class FenwickTree {
public:
  FenwickTree(int n) : sums_(n+1, 0){}
  void update(int i, int delta) {
    while(i < sums_.size()) {
      sums_[i] += delta;
      i += lowbit(i);
    }
  }

  int query(int i) {
    int sum = 0;
    while(i > 0) {
      sum += sums_[i];
      i -= lowbit(i);
    }
    return sum;
  }
private:
  static inline int lowbit(int x) {
    return x & (-x);
  }
  vector<int> sums_;
};

class Solution {
public:
  int createSortedArray(vector<int> &instructions) {
    int n = instructions.size();
    int kMod = 1e9 + 7;
    FenwickTree smallTree(n);
    FenwickTree bigTree(n);

    vector<int> arraycpy(instructions);
    sort(arraycpy.begin(), arraycpy.end());

    int res = 0;
    for(int num : instructions) {
      int lowrank = upper_bound(arraycpy.begin(), arraycpy.end(), num) - arraycpy.begin(); // [1, n] # of numbers <= num
      int upperrank = arraycpy.end() - upper_bound(arraycpy.begin(), arraycpy.end(), num) + 1; // [1, n] # of numbers >= num

      res = (res + min(smallTree.query(lowrank - 1), bigTree.query(upperrank - 1))) % kMod;
      smallTree.update(lowrank, 1);
      bigTree.update(upperrank, 1);
    }
    return res;
  }
};
