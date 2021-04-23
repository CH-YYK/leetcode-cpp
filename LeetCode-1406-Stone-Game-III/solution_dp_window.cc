#include <string>
#include <vector>
using namespace std;

// dp[i] = max_j{ sum(stones[i:i+j]) - dp[i+j+1]}
/* i + j + 1 = k and j in [1, 2, 3]
 * dp[n-1] = stones[n-1];

 * Sliding window for sum might not work we need to test 3 sums for every i
 * But we could pre-compute the prefix sum.

 * Since for each i, it may need to involve c = dp[i+1], b = dp[i+2], a = dp[i+3]
 * size could be reduced to 3 numbers instead of n;
 */

class Solution {
public:
  string stoneGameIII(vector<int> &stoneValue) {
    int n = stoneValue.size();

    int a = 0, b = 0, c = 0;
    int nc = -1e9;
    for (int i = n - 1; i >= 0; --i) {
      int sum_ = 0;
      if (i + 1 <= n) {
        sum_ += stoneValue[i];
        nc = max(nc, sum_ - c);
      }

      if (i + 2 <= n) {
        sum_ += stoneValue[i + 1];
        nc = max(nc, sum_ - b);
      }

      if (i + 3 <= n) {
        sum_ += stoneValue[i + 2];
        nc = max(nc, sum_ - a);
      }
      a = b, b = c, c = nc;
      nc = -1e9;
    }

    if (c > 0)
      return "Alice";
    else if (c < 0)
      return "Bob";
    else
      return "Tie";
  }
};
