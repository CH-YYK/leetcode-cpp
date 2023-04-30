#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

/* Using binary search to find the minimum capacity C
 * C >= max(weights) and C < sum(weights)
 */

class Solution {
public:
  int shipWithinDays(vector<int> &weights, int D) {
    int l = *max_element(weights.begin(), weights.end());
    int r = accumulate(weights.begin(), weights.end(), 0);
    // if c is too small, -> take more than D partitions to seprate the
    // packages, increase c if c is too big, -> take less than D partitions to
    // separate packages, decrease c
    //
    // Find a C where C >= l && C < r, such that n <= D, l -> r at final step
    // O(NlogN)

    vector<int> presum(weights.size() + 1, 0);
    for(int i = 0; i < weights.size(); ++i)
      presum[i+1] = presum[i] + weights[i];

    while (l < r) {
      int m = l + (r - l) / 2;
      // partitions
      if (check(presum, D, m))  // m is a possible answer or too large
        r = m;
      else  // m is too small
        l = m + 1;
    }
    return l;
  }
private:
  /* Check whether the capacity (C) can fullfill shipping days <= D
   * O(NlogN)
   * At each step, search for the right edge from the left edge, each step will build a partition
   * If right edge touches the end within D steps => num(partitions) <= D -> true
   */
  bool check(vector<int>& presum, int D, int C) {
    auto p = presum.begin();
    while(D-- > 0) {
      p = upper_bound(p, presum.end(), (p == presum.begin() ? C : *(prev(p)) + C));
      if(p == presum.end()) return true;
    }
    return false;
  }
};
