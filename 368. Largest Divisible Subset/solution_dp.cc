#include <vector>
#include <algorithm>
#include <utility>
#include <list>
using namespace std;

// 48ms 71%
class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<pair<int, int>> dp(n, {1, -1});  // (cnt, prev)
    int idx = 0, maxcnt = 0;
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < i; ++j) {
        if(nums[i] % nums[j] == 0)
          if(dp[i].first < dp[j].first + 1) {
            dp[i].first = dp[j].first + 1;
            dp[i].second = j;
          }
      }
      if(dp[i].first > maxcnt)
        maxcnt = dp[i].first, idx = i;
    }
    vector<int> ans;
    while(idx >= 0) {
      ans.push_back(nums[idx]);
      idx = dp[idx].second;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
