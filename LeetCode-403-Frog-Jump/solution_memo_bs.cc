#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  // O(N^3) -> O(N^2*logN)
  bool canCross(vector<int> &stones) {
    int n = stones.size();
    memo = vector<vector<int>>(n, vector<int>(n, -1));
    return dfs(stones, 0, 0);
  }

private:
  vector<vector<int>> memo;
  bool dfs(vector<int> &stones, int i, int k) {
    if (i == stones.size() - 1)
      return true;
    if (memo[i][k] >= 0)
      return memo[i][k];
    auto lower =
        lower_bound(stones.begin() + i, stones.end(), stones[i] + k - 1);
    auto higher =
        upper_bound(stones.begin() + i, stones.end(), stones[i] + k + 1);
    for (auto it = lower; it != higher; ++it) {
      if (it == lower)
        continue;
      if (dfs(stones, it - stones.begin(), *it - stones[i]))
        return memo[i][k] = true;
    }
    return memo[i][k] = false;
  }
};
