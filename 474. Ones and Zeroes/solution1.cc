#include <vector>
#include <string>

using namespace std;

/* Multi-dimensional valued 01 knapack
 * dp[i][j][k] size of largest subset of strs[:i] with j 0's and k 1's
 * dp[i][j][k] = dp[i-1][j][k] if including strs[i] exceeds j 0's and k 1's
 * dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-strs[i]_0][k-strs[i]_1] + 1)
 * dp[i][0][0] = 0
 */
class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    int len = strs.size();
    vector<int> nums1;
    vector<int> nums0;
    for(auto& str : strs) {
      int num1 = get_1(str);
      int num0 = str.size() - num1;
      nums1.push_back(num1);
      nums0.push_back(num0);
    }

    vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));

    for(int i = 1; i <= len; ++i) {
      for(int j = 0; j <= m; ++j) {  // 0's
        for(int k = 0; k <= n; ++k) {  // 1's
          if(k >= nums1[i-1] && j >= nums0[i-1])
            dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-nums0[i-1]][k-nums1[i-1]] + 1);
          else
            dp[i][j][k] = dp[i-1][j][k];
        }
      }
    }
    return dp[len][m][n];
  }
private:
  int get_1(string& str) {
    int res = 0;
    for(char c : str) if(c == '1') res++;
    return res;
  }
};
