#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charMap;
    int l = 0, maxLen = 0;
    for (int r = 0; r < s.size(); ++r) {
      if (charMap.count(s[r])) {
        maxLen = max(maxLen, r - l);
        int nextL = charMap[s[r]] + 1;
        while (l < nextL) {
          charMap.erase(s[l]);
          ++l;
        }
      }
      charMap[s[r]] = r;
    }
    return s.empty() ? 0 : max(maxLen, (int)s.size() - l);
  }
};