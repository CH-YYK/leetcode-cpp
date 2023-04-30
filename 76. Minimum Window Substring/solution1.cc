#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    /* use 'chars' and 'flags' to track the state of sliding window
     *  - chars: number of chars required by 't', all zeros shows that 't' has been included in substring [l, r]
     *  - flags: the chars required 't'.
     */
    vector<int> chars(128, 0);
    vector<bool> flags(128, false);

    for(int i = 0; i < t.size(); ++i){
      flags[t[i]] = true;
      ++chars[t[i]];
    }

    int cnt = 0, l = 0, min_l = 0, min_size = s.size() + 1;

    /* Slide from left to right and use [l, r] represent substring
     * If 't' has been found in the substring [l, r] -> cnt == t.size(),
     * try to increase l to get a shorter substring.
     *
     * flags[c] == true -> 'c' is in 't
     '
     * chars[c] > 0 -> need one 'c' to get 't' in [l, r]
     */
    for(int r = 0; r < s.size(); ++r) {
      if(flags[s[r]]) {
        if(--chars[s[r]] >= 0) {
          ++cnt;
        }

        while(cnt == t.size()) {
          if(r - l + 1 < min_size) {
            min_l = l;
            min_size = r - l + 1;
          }

          if(flags[s[l]] && ++chars[s[l]] > 0){
            --cnt;
          }
          ++l;
        }
      }
    }
    return min_size > s.size() ? "" : s.substr(min_l, min_size);
  }
};
