#include <vector>
using namespace std;
/* Try all combination of pairs
 *
 */
class Solution {
public:
  int maxScore(vector<int> &nums) {
    int n = nums.size();
    graph = vector<vector<int>>(n, vector<int>(n, 0));
    memo = vector<vector<int>>(n+1, vector<int>(2 << 14, -1));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        graph[i][j] = gcd(nums[i], nums[j]);
    int mask = 0;
    return dfs(nums, 1, mask);
  }

private:
  vector<vector<int>> graph;
  vector<vector<int>> memo;
  int dfs(vector<int> &nums, int i, int mask) {
    // maxscore obtained starting from ith step
    if (memo[i][mask])
      return memo[i][mask];
    int max_ = 0;
    for (int j = 0; j < nums.size(); ++j) {
      for (int k = 0; k < nums.size(); ++k) {
        if (k == j)
          continue;
        if (mask & (1 << j) || mask & (1 << k))
          continue;
        max_ =
            max(dfs(nums, i + 1, mask + (1 << j) + (1 << k)) + i * graph[j][k],
                max_);
      }
    }
    return memo[i][mask] = max_;
  }
};
