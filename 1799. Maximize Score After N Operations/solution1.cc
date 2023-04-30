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
    // each round will remove 2 numbers from nums
    // (n < 7) make it possible to simulate this process
    //
    // for sequence Sum(i * gcd(x, y)), ideally to group large i with large gcd
    // to make the result more likely maximized
    // O(n*2^(2n)) <= O(14*2^14), n is the depth of recursion stack.
    int n = nums.size() / 2;
    vector<int> dp(1 << 2*n, 0);
    function<int(int, int)> backtrack = [&](int x, int state) {
      if(x == 0) return 0;
      if(dp[state] > 0)
      	return dp[state];
      int ans = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (state & (1 << i)) continue;
        int nextstate = state | (1 << i);
        for (int j = i + 1; j < nums.size(); ++j) {
          if (nextstate & (1 << j)) continue;
          ans = max(ans, x * __gcd(nums[i], nums[j]) +
                             backtrack(x - 1, nextstate | (1 << j)));
        }
      }
      return dp[state] = ans;
    };
    return backtrack(n, 0);
  }
};