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
  int reversePairs(vector<int>& nums) {
    const int n = nums.size();
    // get ranks
    vector<int> numscpy(nums);
    sort(numscpy.begin(), numscpy.end());
    // BIT (size n+1) saves frequencies of ranks[i], BIT::query(i) return number of elements with lower rank than i
    // greatest number is assigned lowest rank 1, smallest number is assigned n
    FenwickTree tree(n);
    int ans = 0;
    for(int i = 0; i < n; ++i) {
      // get the rank of 2*nums[i] and find number of total frequencies of lower ranks in BIT <= (rank-1)
      int rank = numscpy.end() - upper_bound(numscpy.begin(), numscpy.end(), 2l * nums[i]) + 1;
      ans += tree.query(rank-1);  // add the counts with lower rank than 'rank'
      int currank = numscpy.end() - upper_bound(numscpy.begin(), numscpy.end(), nums[i]) + 1;
      tree.update(currank, 1);
    }
    return ans;
  }
};
