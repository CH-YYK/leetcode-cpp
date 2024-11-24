#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    // Improvement on solution2.cc.
    //
    // Instead of saving the pattern as a series of strings, we save it as a
    // series of 64-bit integers, and query the map by a vector of integers.
    int m = matrix.size();
    int n = matrix[0].size();
    map<vector<uint64_t>, int> keys;
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      vector<uint64_t> keys1((n + 63) / 64, 0);
      vector<uint64_t> keys2((n + 63) / 64, 0);
      for (int j = 0; j < n; ++j) {
        keys1[j / 64] |= ((uint64_t)matrix[i][j] << (j % 64));
        keys2[j / 64] |= ((uint64_t)(matrix[i][j] ^ 1) << (j % 64));
      }
      ans = max(ans, ++keys[keys1]);
      ans = max(ans, ++keys[keys2]);
    }
    return ans;
  }
};