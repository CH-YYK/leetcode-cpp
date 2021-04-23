#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  string stoneGameIII(vector<int> &stoneValue) {
    int n = stoneValue.size();
    memo = vector<int>(n + 1, -1);
    int res = dfs(stoneValue, 0);

    if (res > 0)
      return "Alice";
    else if (res < 0)
      return "Bob";
    else
      return "Tie";
  }

private:
  vector<int> memo;

  int dfs(vector<int> &stones, int i) {
    if (i == stones.size())
      return 0;
    if(memo[i] > -1) return memo[i];
    int res = -1e9;
    int sum_ = 0;
    for (int j = i; j < min(i + 3, (int)stones.size()); ++j) { // edge case
      sum_ += stones[j];
      res = max(res, sum_ - dfs(stones, j + 1));
    }
    return memo[i] = res;
  }
};


// dp[i] = max_j{ sum(stones[i:i+j]) - dp[i+j+1]}
/* i + j + 1 = k and j in [1, 2, 3]
 * dp[n-1] = stones[n-1];
 */
