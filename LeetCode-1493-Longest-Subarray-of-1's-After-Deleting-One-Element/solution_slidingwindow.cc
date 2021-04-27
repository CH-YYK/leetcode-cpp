#include <vector>
using namespace std;

/* Subarray problem -> sliding window
 * window state: sum == size && sum == size-1
 *  * l++, if sum < size-1
 */
class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int l = 0;
    int sum = 0, len = 0;
    for (int r = 0; r < nums.size(); ++r) {
      sum += nums[r];
      if (sum < r - l) // if works equivalent as while here
        sum -= nums[l++];
      // we must delete 1 elements for any reason. so compare r - l and len after while loop
      len = max(len, r - l);
    }
    return len;
  }
};
