#include <vector>

using namespace std;

class Solution {
public:
  bool stoneGame(vector<int> &piles) {
    int n = piles.size();
    memo = vector<vector<int>>(n, vector<int>(n, -1));
    return score(piles, 0, n-1);
  }

private:
  vector<vector<int>> memo;
  // the maximum relative score for the player at this round from subarray
  // s[l:r]
  int score(vector<int> &s, int l, int r) {
    if (l > r)
      return 0;
    if (l == r)
      return s[l];
    if(memo[l][r] >= 0) return memo[l][r];
    return memo[l][r] = max(s[l] - score(s, l + 1, r), s[r] - score(s, l, r - 1));
  }
};
