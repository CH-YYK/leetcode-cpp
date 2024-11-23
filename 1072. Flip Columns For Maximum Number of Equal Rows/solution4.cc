#include <bitset>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    // Improvement to solution1.cc.
    //
    // Instead of saving all digits in row, we can compress the row into a
    // series of numbers, each number can represent 64 digits.
    // Thus, 300-sized row can be compressed into 5 numbers at most.
    int m = matrix.size();
    int n = matrix[0].size();
    int ans = 0;
    // (n + 63) / 64.  if n = 64, then 1, if n < 128, then 2.
    unordered_map<bitset<300>, int> keys;
    for (int i = 0; i < m; ++i) {
      bitset<300> key1;
      bitset<300> key2;
      for (int j = 0; j < n; ++j) {
        key1[j] = matrix[i][j];
        key2[j] = matrix[i][j] ^ 1;
      }
      ans = max(ans, ++keys[key1]);
      ans = max(ans, ++keys[key2]);
    }
    return ans;
  }
};