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
    while (l < r) {
      int m = l + (r - l) / 2;
      if (check(weights, D, m))  // m is a possible answer or too large
        r = m;
      else  // m is too small
        l = m + 1;
    }
    return l;
  }
private:
  bool check(vector<int>& weights, int D, int C) {
    int n = 1, sum = 0;
    for(int i = 0; i < weights.size(); ++i) {
      sum += weights[i];
      if(sum > C) n++, sum = weights[i];
    }
    return n <= D;
  }
};
