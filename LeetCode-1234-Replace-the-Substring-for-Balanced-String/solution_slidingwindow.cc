#include <string>
#include <vector>
using namespace std;

/* Substring-> sliding window
 * substring should be the minimized substring that covered all extra characters
 * window state: vector of size 26 to track the counts of 'Q''W''E''R'
 * when update: all extra characters covered
 */
class Solution {
public:
  int balancedString(string s) {
    int n = s.size(), m = n / 4;
    vector<int> cnt(26, 0);
    for (char c : s)
      cnt[c - 'A']++;
    for (int i = 0; i < 26; ++i)
      if (cnt[i] > m)
        cnt[i] -= m;
      else
        cnt[i] = 0;
    if (cnt == vector<int>(26, 0))
      return 0;
    int l = 0, len = n;
    vector<int> state(26, 0);
    for (int r = 0; r < n; ++r) {
      state[s[r] - 'A']++;
      while (check(state, cnt)) {
        len = min(len, r - l + 1);
        state[s[l++] - 'A']--;
      }
    }
    return len;
  }

private:
  bool check(vector<int> &state, vector<int> &cnt) {
    int res = true;
    for (int i = 0; i < 26; ++i)
      if (cnt[i] > 0)
        res &= state[i] >= cnt[i];
    return res;
  }
};
