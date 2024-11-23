#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    // no limitation on number of flips
    // making a row all 0 or all 1 doesn't really matter.
    // if we make a row all same, then the rest are already determined.
    //
    // so we can try making each row same for once, and check the rest to see
    // how many same rows we get.
    //
    // This way might be too costly, so we probably can get which two rows would
    // be always same. if XOR of row_i and row_j are all 0 or all 1, then row_i
    // and row_j will be same at the same time. Comparing 300 for a row is too
    // large, try merging them to several 64 long numbers, then we'd have 3
    // numbers at most per row.
    int m = matrix.size();
    int n = matrix[0].size();
    // (n + 63) / 64.  if n = 64, then 1, if n < 128, then 2.
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