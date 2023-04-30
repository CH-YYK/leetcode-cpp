#include <string>
#include <vector>
using namespace std;

/* Two strings, compare substrings, range-based DP
 * dp[i][j][k] = whether s2[j:j+k] is a scramble string of s1[i:i+k]
 */

class Solution {
public:
  bool isScramble(string s1, string s2) {
    int n = s1.size();
    memo = vector<vector<vector<int>>> (n, vector<vector<int>>(n, vector<int>(n + 1, -1)));
    return dfs(s1, s2, 0, 0, n);
  }
private:
  vector<vector<vector<int>>> memo;
  bool dfs(string& s1, string& s2, int i, int j, int len) {
    if(s1.substr(i, len) == s2.substr(j, len)) return true;
    if(memo[i][j][len] != -1) return memo[i][j][len];

    vector<int> vec1(26, 0), vec2(26, 0);
    for(int k = 0; k < len; ++k) {
      vec1[s1[i+k] - 'a']++;
      vec2[s2[j+k] - 'a']++;
    }
    if(! (vec1 == vec2)) return memo[i][j][len] = false;

    for(int k = 1; k < len; ++k) {
      // t1[i:i + k] and t2[j:j + k]
      if(dfs(s1, s2, i, j, k) && dfs(s1, s2, i + k, j + k, len-k))
        return memo[i][j][len] = true;
      // t1[i:i+ k] and t2[k-j:k-j+k]
      if(dfs(s1, s2, i, j + len - k, k) && dfs(s1, s2, i + k, j, len-k))
        return memo[i][j][len] = true;
    }
    return memo[i][j][len] = false;
  }
};
