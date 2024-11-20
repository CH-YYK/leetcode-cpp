#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int takeCharacters(string s, int k) {
    // To find the minimum length of L + R, it's equivalent to find the longest
    // substring in the middle where each char has freq <= all_freq[char] - k.
    //
    // Applying sliding-window because l is only incrementing as r increased.
    vector<int> allFreq(3, 0);
    vector<int> freq(3, 0);
    for (char c : s)
      allFreq[c - 'a']++;
    if (allFreq[0] < k || allFreq[1] < k || allFreq[2] < k) return -1;
    int l = 0, maxlen = 0;
    for (int r = 0; r < s.size(); ++r) {
      freq[s[r] - 'a']++;
      while (l <= r && (freq[0] > allFreq[0] - k || freq[1] > allFreq[1] - k ||
                        freq[2] > allFreq[2] - k))
        freq[s[l++] - 'a']--;
      maxlen = max(r - l + 1, maxlen);
    }
    return s.size() - maxlen;
  }
};