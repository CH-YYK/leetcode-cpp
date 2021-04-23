#include <memory>
#include <vector>

using namespace std;

class FenwickTree {
public:
  FenwickTree(int n) : sums_(n + 1, 0) {}
  void update(int i, int delta) {
    while (i < sums_.size()) {
      sums_[i] += delta;
      i += lowbit(i);
    }
  }
  int query(int i) const {
    int sum = 0;
    while (i > 0) {
      sum += sums_[i];
      i -= lowbit(i);
    }
    return sum;
  }

private:
  static inline int lowbit(int x) { return x & (-x); }
  vector<int> sums_;
};

class NumArray {
public:
  NumArray(vector<int> &nums)
      : _nums(move(nums)), tree(new FenwickTree(_nums.size())) {
    for (int i = 0; i < _nums.size(); ++i)
      tree->update(i + 1, _nums[i]);
  }
  void update(int index, int val) {
    tree->update(index + 1, val - _nums[index]);
    _nums[index] = val;
  }
  int sumRange(int left, int right) {
    // sums_[i+1]: sum(nums_[:i+1])
    // sums_[i+1] - sums_[j] = sum(nums_[j:i+1])
    // susm_[i+1] = nums[0] + nums[1] + ... + nums[i] = sum(nums[:i+1])
    int rightsum = tree->query(right + 1);
    int leftsum = tree->query(left);
    return rightsum - leftsum;
  }

private:
  vector<int> _nums;
  unique_ptr<FenwickTree> tree;
};
