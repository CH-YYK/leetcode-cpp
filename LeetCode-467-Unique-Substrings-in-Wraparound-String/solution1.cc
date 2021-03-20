#include <vector>

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int findSubstringInWraproundString(string p) {
    // dp[i][j] -> whether p[i:j-1] is in s
    // dp[i][j] = dp[i][j-1] if p[j] - p[j-1] == 1 or p[j] - p[j-1] = 25
    // dp[i][i] = true
    int n = p.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    unordered_set<string> set_;
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        if (i == j)
          dp[i][j] = 1;
        else if (p[j] - p[j - 1] == 1 || p[j] - p[j - 1] == -25)
          dp[i][j] = dp[i][j - 1];
        else
          dp[i][j] = 0;

        if (dp[i][j])
          set_.insert(p.substr(i, j - i + 1));
      }
    }
    return set_.size();
  }
};
