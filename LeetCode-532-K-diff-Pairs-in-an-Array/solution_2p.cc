#include <vector>

using namespace std;
/* After sorting, there is some conditions must be fullfilled
 * nums[l] + k = nums[r] && r > l
 * if nums[l] + k > nums[r] -> r++
 * if nums[l] + k < nums[r] -> l++
 * if nums[l] == nums[l-1] -> l++
 *    (to ensure nums[l] is unique then the pair (nums[l], nums[l] + k) is unique)
 */


class Solution {
public:
  int findPairs(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int l = 0, res = 0, r = 0;
    while(r < nums.size()) {
      if(r <= l) ++r;
      else if(nums[r] > nums[l] + k)
        l++;
      else if(nums[r] == nums[l] + k)
        res++, l++;
      else if(nums[r] < nums[l] + k)
        r++;
      while(l > 0 && l < nums.size() && nums[l] == nums[l-1])
        l++;
    }
    return res;
  }
};
