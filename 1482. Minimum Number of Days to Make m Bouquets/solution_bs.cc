#include <vector>
#include <algorithm>
using namespace std;

/* Brute force: test every possible days of waiting and count # of bouquets that can be made
 * Biary search: using binary search to find x days such that y bouquest can be made, x in [min(days), max(days)]
 */

class Solution {
public:
  int minDays(vector<int> &bloomDay, int m, int k) {
    if (k * m > bloomDay.size())
      return -1;
    int l = *min_element(bloomDay.begin(), bloomDay.end());
    int r = *max_element(bloomDay.begin(), bloomDay.end());
    int n = bloomDay.size();
    // picking rule
    // x = (l + r) / 2; and compute y by m
    // if y < k: l = x + 1
    // if y >= k: r = x (x is possible)
    int tmp[n];
    while (l < r) {
      int x = (l + r) / 2;
      // use sliding window to get the number of bouquets
      int y = 0, i = 0;
      for (int j = 0; j < n; ++j)
        if (bloomDay[j] > x || j - i + 1 == k) {
          if (bloomDay[j] <= x && j - i + 1 == k)
            y++;
          i = j + 1;
        }
      if (y >= m)
        r = x;
      else
        l = x + 1;
    }
    return l;
  }
};
