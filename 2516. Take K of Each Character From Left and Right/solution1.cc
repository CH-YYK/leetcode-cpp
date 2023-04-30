// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
ios_base::sync_with_stdio(0);
cin.tie(NULL);
*/

class Solution {
 public:
  int takeCharacters(string s, int k) {
    // find longest substring such that
    // for each char freq[ch] <= allFreq[ch] - k
    vector<int> allFreq(26, 0), freq(26, 0);
    for (char c : s) allFreq[c - 'a']++;
    if (allFreq[0] < k || allFreq[1] < k || allFreq[2] < k) return -1;
    int l = 0, maxlen = 0;
    for (int r = 0; r < s.size(); ++r) {
      freq[s[r] - 'a']++;
      while (l < r + 1 &&
             (allFreq[0] - freq[0] < k || allFreq[1] - freq[1] < k ||
              allFreq[2] - freq[2] < k))
        freq[s[l++] - 'a']--;
      maxlen = max(r - l + 1, maxlen);
    }
    return s.size() - maxlen;
  }
};