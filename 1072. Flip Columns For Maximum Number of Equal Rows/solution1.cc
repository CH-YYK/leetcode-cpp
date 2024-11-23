#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    // No need for a number, just save the string.
    // 101 and 010 are both saved.
    unordered_map<string, int> keys;
    int ans = 0;
    for (const auto &row : matrix) {
      string key1, key2;
      for (int bit : row) {
        key1 += bit;
        key2 += (bit ^ 1);
      }
      ans = max(ans, ++keys[key1]);
      ans = max(ans, ++keys[key2]);
    }
    return ans;
  }
};