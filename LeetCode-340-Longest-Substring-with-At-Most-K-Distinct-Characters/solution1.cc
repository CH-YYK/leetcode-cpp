#include <unordered_set>
#include <string>


using namespace std;

class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    if(s.empty()) return 0;

    unordered_map<char, int> map_;

    int l = 0, max_size = 0;
    for(int r = 0; r < s.size(); ++r) {
      map_[s[r]]++;

      // use <= rather than == in case `s` doesn't have k distinct characters
      if(map_.size() <= k) { 
        max_size = max(max_size, r-l+1);
      }

      while(map_.size() == k+1) {
        if(--map_[s[l]] == 0) map_.erase(s[l]);
        ++l;
      }
    }
    return max_size;
  }
};
