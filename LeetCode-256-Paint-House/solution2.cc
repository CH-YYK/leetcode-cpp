#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int minCost(vector<vector<int>> &costs) {
    int n = costs.size();
    vector<int> dp(costs[0]);

    for(int i = 1; i < n; ++i) {
      vector<int> tmp = dp;
      dp[0] = min(tmp[1], tmp[2]) + costs[i][0];
      dp[1] = min(tmp[0], tmp[2]) + costs[i][1];
      dp[2] = min(tmp[0], tmp[1]) + costs[i][2];
    }
    return *min_element(dp.begin(), dp.end());
  }
};
