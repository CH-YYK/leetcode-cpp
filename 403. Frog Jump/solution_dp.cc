#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
  // O(N^3) -> O(N^2*logN)
  bool canCross(vector<int> &stones) {
    // dp[i]: can jump to stones[i]
    // dp[0] = true
    // dp[i] = true if dp[j] + step[j] == dp[i] or dp[i] + step[j] - 1 or dp[i]
    // + step[j] + 1 == stones[j]
    unordered_map<int, unordered_set<int>>
        m; // <index, prev steps before stones[index]>
    for (int i = 0; i < stones.size(); ++i)
      m.insert({stones[i], unordered_set<int>()});
    m[stones[0]].insert(0);
    for (int i = 0; i < stones.size(); ++i) {
      for (int k : m[i])
        for (int gap = k - 1; gap <= k + 1; ++gap)
          if (gap > 0 && m.count(stones[i] + gap))
            m[stones[i]].insert(gap);
    }

    return !m[stones.back()].empty();
  }
};
