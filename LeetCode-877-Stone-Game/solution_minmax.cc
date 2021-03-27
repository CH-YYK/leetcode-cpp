#include <vector>

using namespace std;

class Solution {
public:
  bool stoneGame(vector<int> &piles) {
    return score(piles, 0, piles.size()-1);
  }
private:
  // the maximum relative score for the player at this round from subarray s[l:r]
  int score(vector<int>& s, int l, int r) {
    if(l > r) return 0;
    if(l == r) return s[l];
    return max(s[l] - score(s, l + 1, r),
               s[r] - score(s, l, r-1));
  }
};
