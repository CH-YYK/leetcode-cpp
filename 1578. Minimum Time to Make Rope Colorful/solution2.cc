#include <algorithm>
#include <numeric>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minCost(string colors, vector<int> &neededTime) {
    int n = colors.size();
    // partition the colors to various adjacent partitions of consecutive
    // colors. the minimum cost of each partition is (sum - max).
    //  Time: O(N)
    //
    // Optimize: sum all 'maxcost' of each partition, which will subtracted from
    // sum.
    int l = 0, maxsum = 0, currmax = neededTime[l];
    for (int r = 0; r <= n; ++r) {
      if (r < n && colors[r] == colors[l]) {
        currmax = max(currmax, neededTime[r]);
      } else {
        maxsum += currmax;
        if (r < n)
          l = r, currmax = neededTime[l];
      }
    }
    return accumulate(neededTime.begin(), neededTime.end(), 0) - maxsum;
  }
};