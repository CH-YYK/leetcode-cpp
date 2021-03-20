#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  // dp[i] -> size of longest string chain ended at word_i
  // dp[i] = max(dp[j]) + 1 if 0 <= j < i & ispred(words[j], words[i]);
  // dp[0] = 1
  int longestStrChain(vector<string> &words) {
    int n = words.size();
    sort(words.begin(), words.end(),
         [&](string &lhs, string &rhs) { return lhs.length() < rhs.length(); });
    vector<int> dp(n, 1);

    int res = 0;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (is_pred(words[j], words[i]))
          dp[i] = max(dp[j] + 1, dp[i]);
        res = max(res, dp[i]);
      }
    }
    return res;
  }

private:
  bool is_pred(const string &lhs, const string &rhs) {
    if (lhs.length() + 1 != rhs.length())
      return false;
    int l = 0, r = 0;
    while (l < lhs.length() && r < rhs.length()) {
      if (lhs[l] == rhs[r])
        l++, r++;
      else
        r++;
    }
    return l == lhs.length();
  }
};
