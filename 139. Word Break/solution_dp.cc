#include <string>
#include <unordered_set>
#include <vector>
using namespace std;


/* dp[i] -> whether s[0:i] (exclude s[i]) can meet the condition
 * * dp[i] = true if there is one k such that s[k:i] in wordDict and s[k] is true
 * * dp[i] = false if there is no k that make s[k:i] in wordDict or s[k] is true
 * -> dp[i] = dp[k] if s[k:i] in wordDict
 * -> dp[0] = true;
 O(N^2)
 */
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    if(s.empty()) return true;
    int n = s.size();
    unordered_set<string> word_dict;
    for(string& w : wordDict)
      word_dict.insert(w);
    vector<int> dp(n+1, false);
    dp[0] = true;
    for(int i = 1; i <= n; ++i) {
      for(int j = 0; j < i; ++j) {
        if(word_dict.count(s.substr(j, i-j)))
          dp[i] = dp[i] || dp[j];
      }
    }
    return dp[n];
  }
};
