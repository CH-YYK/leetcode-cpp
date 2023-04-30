#include <vector>
#include <limits>
#include <numeric>

using namespace std;

class Solution {
public:
  int stoneGameII(vector<int> &piles) {
    int S = accumulate(piles.begin(), piles.end(), 0);
    return (S + score(piles, 0, 1)) / 2;
  }

private:
  int score(vector<int> &s, int i, int M) {
    if (i == s.size())
      return 0;
    int cumsum = 0;
    int maxscore = INT_MIN;
    for (int j = i; j < i + 2 * M && j < s.size(); ++j) {
      cumsum += s[j];
      maxscore = max(maxscore, cumsum - score(s, j + 1, max(j - i + 1, M)));
    }
    return maxscore;
  }
};
