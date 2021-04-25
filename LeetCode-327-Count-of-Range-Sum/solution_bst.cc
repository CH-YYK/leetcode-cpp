#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class FenwickTree {
public:
  FenwickTree(int n) : sums_(n + 1, 0) {}
  void update(int idx, int delta) {
    while(idx < sums_.size()) {
      sums_[idx] += delta;
      idx += lowbit(idx);
    }
  }

  int query(int idx) {
    int sum = 0;
    while(idx > 0) {
      sum += sums_[idx];
      idx -= lowbit(idx);
    }
    return sum;
  }
private:
  vector<int> sums_;
  static inline int lowbit(int x) {
    return x & (-x);
  }
};


class Solution {
public:
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    const int n = nums.size();
    FenwickTree tree(n + 1);
    vector<long> presum(n + 1, 0);
    for(int i = 0; i < n; ++i)
      presum[i+1] = presum[i] + nums[i];
    vector<long> presumcpy(presum);
    sort(presumcpy.begin(), presumcpy.end());

    int res = 0;
    for(int i = 0; i < n+1; ++i){
      // rank(val): # of elements <= val
      int h_rank = upper_bound(presumcpy.begin(), presumcpy.end(), presum[i] - lower) - presumcpy.begin();
      int l_rank = upper_bound(presumcpy.begin(), presumcpy.end(), presum[i] - upper - 1) - presumcpy.begin();
      res += tree.query(h_rank) - tree.query(l_rank);
      int cur_rank = upper_bound(presumcpy.begin(), presumcpy.end(), presum[i]) - presumcpy.begin();
      tree.update(cur_rank, 1);
    }
    return res;
  }
};
