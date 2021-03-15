#include <vector>

using namespace std;

/* (i,j++) -> (i++, j) -> (i, j--) -> (i--, j)
 * In every iteration, we
 *  1. Push current value
 *  2. Advance index to next
 *  3. Fix the next index if it went somewhere wrong. (update margin)
 *
 * My mistakes
 *  1. Tried to use a narrower margin and made mistake in advancing index.
 */
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> res;
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int l = -1, t = -1, r = n, b = m;
    int i = 0, j = 0, di = 0;
    // i take [t, b], j take [l, r]
    for (int k = 0; k < m * n; ++k) {
      di %= 4;
      res.push_back(matrix[i][j]);
      i += dirs[di][0];
      j += dirs[di][1];
      if (j == r)
        i++, j--, t++, di++;
      else if (i == b)
        i--, j--, r--, di++;
      else if (j == l)
        j++, i--, b--, di++;
      else if (i == t)
        i++, j++, l++, di++;
    }
    return res;
  }
};
