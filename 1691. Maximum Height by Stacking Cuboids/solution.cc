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
  int maxHeight(vector<vector<int>> &cuboids) {
    // Sort and LIS: after sorting, it is kind of equivalent to 
    // 		find the largest sequence of cuboids with maximum height
    // each cuboid has 6 ways of positioning.
    // 
    // each cuboids have 6 ways to arrange
    // dp[i][k] := max height for including cuboids[i] and kth arrangement
    // Complexity O(36*N^2)
    function<int(vector<int> &, vector<int> &)> sorter = [](vector<int> &lhs,
                                                            vector<int> &rhs) {
      return lhs[0] + lhs[1] + lhs[2] > rhs[0] + rhs[1] + rhs[2];
    };
    sort(cuboids.begin(), cuboids.end(), sorter);
    int n = cuboids.size();

    vector<vector<int>> dp(n, vector<int>(6, 0));
    for (int i = 0; i < n; ++i)
      for (int k = 0; k < 6; ++k)
        dp[i][k] = cuboids[i][pos[k][2]];
    int res = 0;
    for (int i1 = 0; i1 < n; ++i1) {
      for (int k1 = 0; k1 < 6; ++k1) {
        for (int i2 = 0; i2 < i1; ++i2) {
          for (int k2 = 0; k2 < 6; ++k2) {
            if (canPlace(cuboids, i1, i2, k1, k2))
              dp[i1][k1] =
                  max(dp[i1][k1], dp[i2][k2] + cuboids[i1][pos[k1][2]]);
          }
        }
        res = max(dp[i1][k1], res);
      }
    }

    return res;
  }
private:
  vector<vector<int>> pos = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2},
                             {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
  bool canPlace(vector<vector<int>> &cuboids, int i1, int i2, int k1, int k2) {
    // 012, 021, 102, 120, 201, 210
    // can (i1,k1) be placed on (i2,k2)
    return cuboids[i1][pos[k1][0]] <= cuboids[i2][pos[k2][0]] &&
           cuboids[i1][pos[k1][1]] <= cuboids[i2][pos[k2][1]] &&
           cuboids[i1][pos[k1][2]] <= cuboids[i2][pos[k2][2]];
  }
};


int main() {}
