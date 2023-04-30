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

class Solution {
 public:
  int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes,
                    int maxWeight) {
    // trip = portChanges + 2
    // dp[i] := trips for boxes[:i]
    // find a left such that dp[right + 1] = dp[left] + trip
    // increment left iff dp[left] = dp[left + 1], put boxes to the
    //  previous loading round at the same cost, s.t. more boxes can be loaded
    //  this round.
    //
    int n = boxes.size();
    int l = 0;
    int t = 0;
    int weight = 0;
    vector<int> dp(n + 1, 0);
    for (int r = 0; r < n; ++r) {
      if (r > 0 && boxes[r][0] != boxes[r - 1][0]) t++;
      weight += boxes[r][1];
      while (weight > maxWeight || r - l + 1 > maxBoxes ||
             (l < r && dp[l] == dp[l + 1])) {
        weight -= boxes[l++][1];
        if (boxes[l][0] != boxes[l - 1][0]) --t;
      }
      // +2 means leave and return
      dp[r + 1] = dp[l] + t + 2;
    }
    return dp[n];
  }
};
