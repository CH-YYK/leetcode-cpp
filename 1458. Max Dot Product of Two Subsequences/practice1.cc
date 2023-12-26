#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
    //
    // Let dp[i][j] := max dot product for nums1[:i+1] and nums2[:j+1]
    // dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i][j] + nums1[i] * nums2[j])
    //
    // The exception that should be noted is there must be at least 1 pair of
    // numbers to compute the dot product
    // 
    // So:
    //   dp[0][0] = nums1[0] * nums2[0]
    //   dp[i][0] = max(nums1[i] * nums2[0])
    //   dp[0][j] = max(nums2[j] * nums1[0])
    int n1 = nums1.size(), n2 = nums2.size();
    vector<vector<int>> dp(n1, vector<int>(n2, INT_MIN));

    dp[0][0] = nums1[0] * nums2[0];
    for (int i = 1; i < n1; ++i)
      dp[i][0] = max(dp[i - 1][0], nums1[i] * nums2[0]);
    for (int j = 1; j < n2; ++j)
      dp[0][j] = max(dp[0][j - 1], nums1[0] * nums2[j]);

    for (int i = 1; i < n1; ++i) {
      for (int j = 1; j < n2; ++j) {
        int _curr = nums1[i] * nums2[j];
        
        // drop all past elements
        dp[i][j] = _curr;
        // dp[i-1][j-1] + nums1[i] * nums2[j]
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + _curr);
        // dp[i-1][j] or dp[i][j-1]
        dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
      }
    }
    return dp[n1-1][n2-1];
  }
};