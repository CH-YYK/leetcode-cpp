#include <utility>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int deleteAndEarn(vector<int> &nums) {
    // similar to house robber dp
    // use a hashmap, dp to store the maximum sum ended by num,
    //   and use '0' to indicate that num is added while '1' indicating that it is not
    //
    // if num - 1 != prev: can keep both prev and num
    //   dp[num][0] = count[num] * num + max(dp[prev][0], dp[prev][1])
    //   dp[num][1] = max(dp[prev][0], dp[prev][1])
    // else
    //   dp[num][0] = count[num] * num + dp[prev][1]
    //   dp[num][1] = max(dp[prev][0], dp[prev][1])
    //

    vector<int> count(10001, 0);
    for (int num : nums)
      count[num]++;
    unordered_map<int, pair<int, int>> dp;
    int prev = 0;
    dp[prev].first = 0;
    dp[prev].second = 0;

    for (int i = 1; i <= 10000; ++i) {
      if (count[i] == 0)
        continue;
      int m = max(dp[prev].first, dp[prev].second);
      if (i - 1 != prev) {
        dp[i].second = i * count[i] + m;
        dp[i].first = m;
      } else {
        dp[i].second = i * count[i] + dp[prev].first;
        dp[i].first = m;
      }
      prev = i;
    }
    return max(dp[prev].first, dp[prev].second);
  }
};
