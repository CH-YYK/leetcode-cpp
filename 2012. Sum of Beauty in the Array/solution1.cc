#include <vector>

using namespace std;

class Solution {
public:
  int sumOfBeauties(vector<int> &nums) {
    // condition 1: nums[i] is the single max of nums.
    // condition 2: nums[i] is greater than nums[i-1] and less than nums[i + 1].
    //
    // both condition is easy to verify.

    int sum = 0;
    int max_num = INT_MIN, cnt = 0;
    int left_max = nums[0];
    // right_max[i] the min number in nums[i+1:]
    vector<int> right_min(nums.size(), INT_MAX);
    for (int i = nums.size() - 2; i >= 0; --i)
      right_min[i] = min(right_min[i + 1], nums[i + 1]);
    for (int i = 1; i < nums.size() - 1; ++i) {
      if (nums[i] > left_max && nums[i] < right_min[i]) {
        sum += 2;
      } else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) {
        sum += 1;
      }
      left_max = max(left_max, nums[i]);
    }
    return sum;
  }
};