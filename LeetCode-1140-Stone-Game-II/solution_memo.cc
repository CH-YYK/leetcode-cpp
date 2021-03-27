#include <limits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  int stoneGameII(vector<int> &piles) {
    int S = accumulate(piles.begin(), piles.end(), 0);
    int n = piles.size();
    memo = vector<vector<int>>(n, vector<int>(2*n, -1));
    return (S + score(piles, 0, 1)) / 2;
  }

private:
  vector<vector<int>> memo;
  int score(vector<int> &s, int i, int M) {
    if (i == s.size())
      return 0;
    if(memo[i][M] >= 0) return memo[i][M];
    int cumsum = 0;
    int maxscore = INT_MIN;
    for (int j = i; j < i + 2 * M && j < s.size(); ++j) {
      cumsum += s[j];
      maxscore = max(maxscore, cumsum - score(s, j + 1, max(j - i + 1, M)));
    }
    return memo[i][M] = maxscore;
  }
};
