#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    // offline method, hashtable/hashset, (key)
    // start from a number key, iteratively delete its neighbors and update
    // maximum length
    int res = 0;
    unordered_set<int> s;
    for (int num : nums)
      s.insert(num);
    while (!s.empty()) {
      int curr = *s.begin();
      s.erase(curr);
      int prev = curr - 1;
      int next = curr + 1;
      while (s.count(prev))
        s.erase(prev--);
      while (s.count(next))
        s.erase(next++);
      res = max(res, next - prev - 1);  // next - prev + 1 - 2 = next-prev-1;
    }
    return res;
  }
};
