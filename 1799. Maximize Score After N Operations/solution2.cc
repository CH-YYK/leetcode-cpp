// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
ios_base::sync_with_stdio(0);
cin.tie(NULL);
*/

class Solution {
 public:
  int maxScore(vector<int>& nums) {
    // n < 7
    // bottom-up version solution
    // dp[k][state] = max(dp[k-1][prestate]), where k is the coef
    int n = nums.size();
    vector<vector<int>> dp(n / 2 + 1, vector<int>(1 << n, 0));
    for (int mask = 0; mask < (1 << n); ++mask) {
      int c = __builtin_popcount(mask);
      if (c & 1) continue;  // no odd counts
      int k = c / 2 + 1;    // coef
      for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
          if ((mask & (1 << i)) || (mask & (1 << j))) continue;
          int nxtmask = mask | (1 << i) | (1 << j);
          dp[k][nxtmask] = max(dp[k - 1][mask] + __gcd(nums[i], nums[j]) * k,
                               dp[k][nxtmask]);
        }
    }
    return dp[n / 2][(1 << n) - 1];
  }
};