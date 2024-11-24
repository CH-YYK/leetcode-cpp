#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    // Improvement on solution1.cc.
    //
    // Instead of saving the pattern as a string, we save it as a series of
    // 64-bit integers. If there are 300 columns per row, then we need 5 numbers
    // to save the pattern.
    int m = matrix.size();
    int n = matrix[0].size();
    unordered_map<string, int> keys;
    for (int i = 0; i < m; ++i) {
      vector<uint64_t> keys1((n + 63) / 64, 0);
      vector<uint64_t> keys2((n + 63) / 64, 0);
      for (int j = 0; j < n; ++j) {
        keys1[j / 64] |= ((uint64_t)matrix[i][j] << (j % 64));
        keys2[j / 64] |= ((uint64_t)(matrix[i][j] ^ 1) << (j % 64));
      }
      string key1, key2;
      for (int i = 0; i < keys1.size(); ++i) {
        key1 += to_string(keys1[i]) + ",";
        key2 += to_string(keys2[i]) + ",";
      }
      keys[key1]++;
      keys[key2]++;
    }
    int ans = 0;
    for (const auto &[key, count] : keys) {
      ans = max(ans, count);
    }
    return ans;
  }
};