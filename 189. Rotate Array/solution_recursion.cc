#include <vector>
using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    k %= n;
    if (k == 0)
      return;
    helper(nums, 0, n - k);
  }

private:
  void helper(vector<int> &nums, int l, int r) {
    if(r == nums.size()) return;
    if (l >= r) return;
    int rmin = r;
    while(l < rmin && r < nums.size())
      swap(nums[l++], nums[r++]);
    if(l == rmin) helper(nums, l, r); // buffer is too large and shrink the buffer size
    else helper(nums, l, rmin);  // buffer is small enough to be placed in array
  }
};
