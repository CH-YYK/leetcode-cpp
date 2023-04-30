#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

/* brute force: try all possible sums and keep the first one that make up m partitions
 * binary search: try x as the largest sum, get y partitions , we want y == m, more x will get less y
 *  * if(y <= m): (x is possible) : increase y, reduce x, r = x
 *  * if(y > m) : reduce y, increase x, l = x + 1
 */
class Solution {
public:
  int splitArray(vector<int> &nums, int m) {
    int l = *max_element(nums.begin(), nums.end());
    int r = accumulate(nums.begin(), nums.end(), 0);
    while(l < r) {
      int x = (l + r) / 2;
      // y refer to the yth partition we are going to fill
      // and we are currently at yth partiion
      int y = 1, sum = 0;  
      for(int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if(sum > x) y++, sum = nums[i];  // 1 partition filled and open new one
      }
      if(y <= m) r = x;
      else l = x + 1;
    }
    return l;
  }
};
