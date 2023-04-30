#include <vector>
#include <algorithm>
using namespace std;

/* Brute force: try all possible divisors and sum the division results respectively, find the smallest one
   that make the result <= threshold
 * Binary search: use Binary search to find the divisor x and compute the result y, greater divisor get smaller division result
 *  if y <= threshold: (y is possible) : r = x
 *  if y > threshold: l = x + 1;
 */
class Solution {
public:
  int smallestDivisor(vector<int> &nums, int threshold) {
    int l = 1, r = *max_element(nums.begin(), nums.end());
    /* Greater divisor cause smaller division result
     */
    while (l < r) {
      int m = (l + r) / 2;
      int y = 0;
      for (int i = 0; i < nums.size(); ++i)
        y += nums[i] / m;
      if (y <= threshold)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
};
