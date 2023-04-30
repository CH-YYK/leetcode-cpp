/* cannot use sliding window as a window may not represent a local optimization
 */

class Solution {
public:
  string longestNiceSubstring(string s) {
    vector<int> chars(126, 0);
    int upper = 0;
    int lower = 0;

    int l = 0, maxl, maxlen;
    for(int i = 0; i < s.size(); ++i) {
      if(chars[s[i]]++ == 0) {
        if(isupper(s[i])) upper += 1 << (s[i] - 'A');
        if(islower(s[i])) lower += 1 << (s[i] - 'a');
      }
      while(upper == lower) {
        if(i - l + 1 > maxlen) {
          maxlen = i - l + 1;
          maxl = l;
        }
        if(--chars[s[l]] == 0) {
          if(isupper(s[l])) upper -= 1 << (s[i] - 'A');
          if(islower(s[i])) lower -= 1 << (s[i] - 'a');
        }
        ++l;
      }
    }
    return maxl == s.size() ? "" : s.substr(maxl, maxlen);
  }
};
