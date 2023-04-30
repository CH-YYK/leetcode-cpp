#include <vector>
#include <algorithm>
using namespace std;

class FenwickTree {
public:
  FenwickTree(int n) : sums_(n+1, 0) {}
  void update(int i, int delta) {
    while(i < sums_.size()) {
      sums_[i] += delta;
      i += lowbit(i);
    }
  }
  int query(int i) const {
    int sum = 0;
    while(i > 0) {
      sum += sums_[i];
      i -= lowbit(i);
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
  vector<int> countSmaller(vector<int>& nums) {
    const int n = nums.size();
    reverse(nums.begin(), nums.end());

    vector<int> numscpy(nums);
    sort(numscpy.begin(), numscpy.end());
    vector<int> ranks(n);
    for (int i = 0; i < n; ++i)  // find corresponding ranks
      ranks[i] = lower_bound(numscpy.begin(), numscpy.end(), nums[i]) -
                 numscpy.begin();

    FenwickTree tree(n);
    vector<int> ans;
    for(int i = 0; i < n; ++i) {
      tree.update(ranks[i] + 1,  1);
      ans.push_back(tree.query(ranks[i]));
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
