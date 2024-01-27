#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// There's some pattern that this problem could be resolved mathematically, but
// still a little complex. Instead, it's better to try finding the state
// transition beneath them.
//
// To compute f(n, k), let's consider the scenario of adding number n to an
// existing array of (1...n-1). We can create (0 ~ n-1) more inverse pairs
// depending on n's position (by creating decreasing pairs).
//
// So f(n, k) = Sum(f(n-1, k)...f(n-1, k - min(n-1, k)));
//

class Solution {
public:
  int kInversePairs(int n, int k) {
    // In Solution2 we have applied 1-d DP method.
    // At every iteration, it needs to compute the cumulative sum for dp[k ~
    // max(0, k - i)] and produce another k iterations.
    //
    // Use prefix sum can mitigate this problem.
    vector<long> dp(k + 1, 0);
    dp[0] = 1;
    vector<long> prefixSum(k + 1 + 1, 1);
    prefixSum[0] = 0;

    int kMod = 1e9 + 7;

    // Start from n = 1, dp[k] = sum(dp[k] ... dp[max(0, k - i + 1)])
    for (int i = 1; i < n; ++i) {
      for (int j = k; j > 0; --j) {
        dp[j] = (prefixSum[j + 1] - prefixSum[max(0, j - i)]) % kMod;
      }
      for (int j = 0; j <= k; ++j) {
        prefixSum[j + 1] = prefixSum[j] + dp[j];
      }
    }
    return dp[k];
  }
};