#include <vector>
using namespace std;

class Solution {
public:
  // sliding window
  int maxAscendingSum(vector<int> &nums) {
    int l = 0, max_ = 0, sum_ = nums[0];
    int n = nums.size();
    for(int i = 1; i < n; ++i) {
      if(nums[i] > nums[i-1]) sum_ += nums[i];
      else {
        max_ = max(max_, sum_);
        l = i;
        sum_ = nums[l];
      }
    }
    max_ = max(max_, sum_);
    return max_;
  }
};
