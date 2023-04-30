#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    vector<int> map_(128, 0);
    // unordered_map<char, int> map_;
    int l = 0, max_size = 0, cnt = 0;

    for(int r = 0; r < s.size(); ++r) {
      if(map_[s[r]]++ == 0) ++cnt;
      if(cnt <= k) max_size = max(max_size, r - l + 1);
      while(cnt == k+1) {
        if(--map_[s[l]] == 0)
          --cnt;
        ++l;
      }
    }
    return max_size;
  }
};
