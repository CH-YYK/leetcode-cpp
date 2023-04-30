#include <string>
#include <vector>
using namespace std;

// dp[i] = max_j{ sum(stones[i:i+j]) - dp[i+j+1]}
/* i + j + 1 = k and j in [1, 2, 3]
 * dp[n-1] = stones[n-1];
 */

class Solution {
public:
  string stoneGameIII(vector<int> &stoneValue) {
    int n = stoneValue.size();
    vector<int> dp(n + 1, -1e9);
    dp[n-1] = stoneValue[n-1];
    dp[n] = 0;
    for(int i = n-1; i >= 0; --i) {
      int sum_ = 0;
      for(int j : {0, 1, 2}) {  // i+0, i+1, i+2
        if (i + j + 1 <= n) {
          sum_ += stoneValue[i + j];
          dp[i] = max(dp[i], sum_ - dp[i + j + 1]);
        }
      }
    }
    if(dp[0] > 0) return "Alice";
    else if(dp[0] < 0) return "Bob";
    else return "Tie";
  }
};
