/* An envelope [w1, h1] can be put inside another one [w2, h2] if w1 < w2 and h1 < h2
 *
 * 1- Sort the vector of envelopes
 * 2- problem is reduced to LIS of envelope[1]
 *    2-1- Solve LIS by using linear search
 * 3- Time complexity: O(N^2)
 */

bool cmp(vector<int>& lhs, vector<int>& rhs) {
  if(lhs[0] < rhs[0]) return true;
  else return false;
}

class Solution {
public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), cmp);
    int n = envelopes.size(), res = 0;
    // dp(i) = max(dp[j], j < i) + 1
    vector<int> dp(n, 0);
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < i; ++j) {
        if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
          dp[i] = max(dp[i], dp[j]);
      }
      res = max(++dp[i], res);
    }
    return res;
  }
};
