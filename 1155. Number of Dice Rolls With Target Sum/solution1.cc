#include <algorithm>
#include <numeric>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int numRollsToTarget(int n, int k, int target) {
    // dfs with early pruning
    memo = vector<vector<int>>(n + 1, vector<int>(target + 1, -1));
    return dfs(n, k, 0, target);
  }

private:
  vector<vector<int>> memo;
  int kMod = 1e9 + 7;
  int dfs(int n, int k, int sum, int target) {
    if (n < 0)
      return 0;
    // Find one path only when it's at last roll and
    // the sum is exactly target.
    if (sum == target && n == 0)
      return 1;
    if (memo[n][sum] >= 0)
      return memo[n][sum];
    int ans = 0;
    for (int i = 1; i <= k & sum + i <= target; ++i) {
      ans = (ans + dfs(n - 1, k, sum + i, target)) % kMod;
    }
    return memo[n][sum] = ans % kMod;
  }
};