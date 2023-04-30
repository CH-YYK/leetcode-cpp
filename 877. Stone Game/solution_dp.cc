#include <vector>

using namespace std;

class Solution {
public:
  bool stoneGame(vector<int> &piles) {
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // subarray of size 0
    for(int i = 0; i < n; ++i)
      dp[i][i] = piles[i];

    // subarray of size 1+
    for(int l = 1; l < n; ++l) {
      for(int i = 0; i < n-l; ++i) {
        int j = i + l - 1;
        dp[i][j] = max(piles[i] - dp[i+1][j],
                       piles[j] - dp[i][j-1]);
      }
    }
    return dp[0][n-1];
  }
};
