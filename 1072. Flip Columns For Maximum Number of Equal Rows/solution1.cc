#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    // There is no limitation on the number of flips, so we can flip a column
    // any time per our needs. Because a flip applies to the whole column, the
    // 1-0 relationship in a column won't be changed. So a 'row' can be inferred
    // by another 'row' no matter how much the columns are flipped.
    //
    // If a row is [1, 0, 1] and another is [0, 1, 0], they'll become "equal
    // rows" at the same time. It applies to the case where a row is [0, 1, 0]
    // and another is [0, 1, 0].
    //
    // If we treat a representation of a row a 'pattern', we can get how many
    // other rows are changed along with this one. The most counts of rows
    // following one 'pattern' is the answer.
    //
    // The pattern is a concatenation of 0s and 1s in a row and it's inverted
    // version. i.e. 101 and 010.
    //
    // Time: O(mn^2), m*n steps for building the pattern, maybe approximately n
    // per pattern for finding in hashmap because they are large strings1.
    // Space: O(m*n)
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