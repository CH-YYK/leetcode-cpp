#include <vector>

using namespace std;

/* State: dp[i] minimum number of swaps required for A[:i] and B[:i]
 * cases:
 *  1. (A[i-1] < A[i] && B[i-1] < B[i]) && (A[i-1] < B[i] && B[i-1] < A[i]) swap at will.
 *  2. (A[i-1] < A[i] && B[i-1] < B[i]) && (A[i-1] > B[i] || B[i-1] > A[i]) swap both or neither
 *  3. (A[i-1] > A[i] || B[i-1] > B[i]) swap i-1 or swap i
 */
class Solution {
public:
  int minSwap(vector<int> &A, vector<int> &B) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i < n; ++i) {
      if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
        if (A[i - 1] < B[i] && B[i - 1] < A[i]) { // swap randomly
          dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
          dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
        } else { // swap both or neigher
          dp[i][0] = dp[i - 1][0];
          dp[i][1] = dp[i - 1][1] + 1;
        }
      } else {
        dp[i][0] = dp[i - 1][1];     // swap i-1 if keep i
        dp[i][1] = dp[i - 1][0] + 1; // swap i if keep i-1
      }
    }
    return min(dp[n - 1][0], dp[n - 1][1]);
  }
};
