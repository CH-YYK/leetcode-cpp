#include <vector>

using namespace std;
/* Iteratively reset buffer size when buffer size is too large to be placed in array
 * always reset the right pointer to the start of buffer
 */
class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    k %= n;
    if (k == 0)
      return;
    int r = n - k;
    for (int l = 0; l < n; ++l) {
      if (r - l < k)
        k -= r - l;
      swap(nums[l], nums[r++]);
      if (r == n)
        r = n - k;
    }
    return;
  }
};
