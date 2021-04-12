#include <vector>
using namespace std;

/* Looking for the pivot index, p, where nums[p] < nums[p-1], so if we find
 * 1. nums[m]< nums[l] -> m at right part -> pivot in [l, m] -> r = m
 * 2. nums[m] >= nums[l] && nums[m] > nums[r] -> m (and l) at left part -> pivot in [m+1, r]
 * 3. nums[m] >= nums[l] && nums[m] < nums[r] -> m (and l) at right part -> pivot is at l
 */

class Solution {
public:
  int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1, m;
    while (l < r) {
      m = (l + r) / 2;
      if (nums[m] >= nums[l]) {
        if (nums[m] > nums[r]) l = m + 1;
        else return nums[l];
      } else if (nums[m] < nums[l])
        r = m;
      else
        return nums[m];
    }
    return nums[l];
  }
};
