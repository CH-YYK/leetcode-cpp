#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    // online method, hashtable: (key, len),
    // key: the number, val: the length of consecutive sequence bounded by key
    // iteratively adding numbers to hashmap and update the lengths of sequences correspondingly
    unordered_map<int, int> m;
    for (int num : nums) {
      if(m.count(num)) continue;
      if (m.count(num - 1) && m.count(num + 1)) {  // connect two sequences and update lengths
        m[num] = m[num + m[num + 1]] = (m[num - m[num - 1]] += m[num + 1] + 1);
      } else if (m.count(num - 1)) {  // add 1 to left sequence and update length
        m[num] = ++m[num - m[num - 1]];
      } else if (m.count(num + 1)) { // add 1 to right sequence and update length
        m[num] = ++m[num + m[num + 1]];
      } else  // initialize a new sequence in hashmap with length 1
        m[num]++;
    }
    int res = 0;
    for (auto p : m) {
      res = max(p.second, res);
    }
    return res;
  }
};
