#include <vector>
using namespace std;

/* lowbit(x) : x&(-x),
 * e.g. 110 & (~110 + 1) -> 110 & (1001 + 1) = 110 & 1010 = 0010
 */

class FenwickTree {
public:
  FenwickTree(int n): sums_(n + 1, 0){}
  void update(int i, int delta) { // O(logn)
    while(i < sums_.size()) {
      sums_[i] += delta;
      i += lowbit(i);
    }
  }
  int query(int i) const {  // O(logn)
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
