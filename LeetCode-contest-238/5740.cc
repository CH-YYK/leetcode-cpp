#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int longestBeautifulSubstring(string word) {
    int n = word.size();
    int l = 0, maxl = 0, len = 0;
    unordered_set<char> set_({'a', 'e', 'i', 'o', 'u'});
    unordered_set<char> tmp = set_;
    for (int r = 0; r < n + 1; ++r) {
      if (r == n || r > 1 && word[r] < word[r - 1]) {
        if (tmp.empty() && r - l > len) {
          maxl = l;
          len = r - l;
        }
        l = r;
        tmp = set_;
      }
      if (r < n && tmp.count(word[r]))
        tmp.erase(word[r]);
    }
    return len;
  }
};
