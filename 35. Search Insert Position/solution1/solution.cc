#include <vector>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    // Find nums[m] >= target.
    int l = 0, r = nums.size();
    while (l < r) {
      int m = (l + r) / 2;
      if (nums[m] == target)
        return m;
      else if (nums[m] < target)
        l = m + 1;
      else
        r = m;
    }
    return l;
  }
};