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
  int countSquares(vector<vector<int>> &matrix) {
    // we are only interested in the squares of 1
    // each square can be identified by corner and length of edge
    // if we know the biggest side l with cornebr (i, j), there will be
    // l unique squares
    // dp[i][j]:= the biggest edge of square with bottom-right at (i,j)
    // dp[0][0] = matrix[0][0] ? 1 : 0;
    // dp[i][j] = matrix[i][j] ?
    //			min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1
    // 				: 0
    // initial states:
    // dp[0][:] = matrix[0][:] and dp[:][0] = matrix[:][0]
    vector<vector<int>> dp = matrix;
    int m = matrix.size(), n = matrix[0].size();
    int res = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (i == 0 || j == 0)
          res += matrix[i][j];
        else if (dp[i][j]) {
          dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
          res += dp[i][j];
        }
      }
    return res;
  }
};

int main() {}
