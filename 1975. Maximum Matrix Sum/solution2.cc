#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  long long maxMatrixSum(vector<vector<int>> &matrix) {
    // Improvement to solution1.cc
    //
    // We simplify the logic to a fact that all absolute values are summed, the
    // minimum absolute values are subtracted twice from that.
    //
    // Time: O(n^2)
    // Space: O(1)
    int min_abs = INT_MAX;
    int num_negatives = 0;
    long long ans = 0;

    for (const auto &row : matrix) {
      for (const auto &num : row) {
        if (num < 0) {
          ans -= num;
          ++num_negatives;
          min_abs = min(min_abs, -num);
        } else {
          ans += num;
          min_abs = min(min_abs, num);
        }
      }
    }

    if (num_negatives & 1)
      return ans - 2ll * min_abs;
    return ans;
  }
};