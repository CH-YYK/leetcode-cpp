#include <bitset>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    // Improvement to solution3.cc.
    //
    // Instead of saving the pattern as a series of integers, we save it as a
    // constant-sized bitset<300> which support hashing.
    int m = matrix.size();
    int n = matrix[0].size();
    int ans = 0;
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