#include <vector>
using namespace std;

/* We are interested in finding the pivot index where nums[pivot-1] < nums[pivot]
 * Start from [l, r] and get m, we then
 * 1. determine where m located, left to pivot or right to pivot.
 *   * if nums[m] < nums[l]: m is right to the pivot or on the pivot
 *   * if nums[m] == nums[l]: m can located either of them, we compare l and r to narrow our hypothesis
 *      * nums[l] < nums[r]: pivot is at start -> return nums[l]
 *      * nums[l] == nums[r]: duplicated numbers -> advance l to skip current case. l++
 *      * nums[l] > nums[r]: then nums[m] > nums[r] -> l = m + 1
 *   * if nums[m] > nums[l]: m located at the same side with l, determine where l located
 *      * nums[l] < nums[r]: return nums[l]
 */
class Solution {
public:
  int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1, m;
    while (l < r) {
      m = (l + r) / 2;
      if (nums[m] > nums[l]) {
        if (nums[l] < nums[r])
          return nums[l];
        l = m + 1;
      } else if (nums[m] == nums[l]) {
        if (nums[l] < nums[r])
          return nums[l];
        else if (nums[l] == nums[r])
          l++;
        else
          l = m + 1;
      } else
        r = m;
    }
    return nums[l];
  }
};
