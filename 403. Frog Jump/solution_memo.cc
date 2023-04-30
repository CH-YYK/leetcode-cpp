#include <vector>
#include <algorithm>

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
  bool dfs(vector<int>& stones, int i, int k) {
    if(i == stones.size() - 1) return true;
    if(memo[i][k] >= 0) return memo[i][k];
    for (int j = i + 1; j < stones.size(); ++j) {
      int gap = stones[j] - stones[i];
      if (gap >= k - 1 && gap <= k + 1)
        if(dfs(stones, j, gap))
          return memo[i][k] = true;
    }
    return memo[i][k] = false;
  }
};
