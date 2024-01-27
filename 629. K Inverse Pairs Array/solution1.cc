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
    // Using DFS + memoization: O(n*k^2) time and space.
    memo = vector<vector<long>>(n + 1, vector<long>(k + 1, -1));
    return dfs(n, k);
  }

private:
  int kMod = 1e9 + 7;
  vector<vector<long>> memo;
  long dfs(int n, int k) {
    if (k == 0)
      return 1;
    if (n == 1)
      return 0;
    if (memo[n][k] >= 0)
      return memo[n][k];
    long ans = 0;
    for (int i = 0; i <= min(n - 1, k); ++i) {
      ans += dfs(n - 1, k - i);
    }
    return memo[n][k] = (ans % kMod);
  }
};