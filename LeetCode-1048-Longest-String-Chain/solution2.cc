#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
  // better one in function body
  // dp[i] -> size of longest string chain ended at word_i
  // dp[i] = max(dp[j]) + 1 if 0 <= j < i & ispred(words[j], words[i]);
  // dp[0] = 1
  int longestStrChain(vector<string> &words) {
    sort(words.begin(), words.end(),
         [&](string &lhs, string &rhs) { return lhs.length() < rhs.length(); });

    unordered_map<string, int> dp;
    int res = 0;
    for (string w : words) {
      for (int i = 0; i < w.length(); i++) { // find all possible previous word
        string pre = w.substr(0, i) + w.substr(i + 1);  // previous one
        dp[w] = max(dp[w], dp.find(pre) == dp.end() ? 1 : dp[pre] + 1);
      }
      res = max(res, dp[w]);
    }
    return res;
  }
};
