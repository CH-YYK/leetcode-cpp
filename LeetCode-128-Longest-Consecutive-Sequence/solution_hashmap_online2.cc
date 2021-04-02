#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    // online method, hashtable: (key, len),
    // key: the number, val: the length of consecutive sequence bounded by key
    // iteratively adding numbers to hashmap and update the lengths of sequences
    // correspondingly
    unordered_map<int, int> m;
    int res = 0;
    for(int num : nums) {
      if(m.count(num)) continue;
      auto it_l = m.find(num-1);
      auto it_r = m.find(num+1);

      int l = it_l != m.end() ? it_l->second : 0;
      int r = it_r != m.end() ? it_r->second : 0;
      int t = l + r + 1;

      m[num] = m[num-l] = m[num+r] = t;
      res = max(res, t);
    }
    return res;
  }
};
