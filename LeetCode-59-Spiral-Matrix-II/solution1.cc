#include <vector>

using namespace std;


/* Define 4 directions
 * Define 4 error margins/timer to change directions
 */
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    int total = n * n;
    vector<vector<int>> res(n, vector<int>(n, 0));
    vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int l = -1, t = -1, b = n, r = n;
    int i = 0, j = 0, di = 0;
    for (int k = 1; k <= total; ++k) {
      di %= 4;
      res[i][j] = k;
      i += dirs[di].first;
      j += dirs[di].second;

      if(j == r) ++i, --j, ++t, ++di;
      else if(i == b) --i, ++j, --r, ++di;
      else if(j == l) --i, ++j, --b, ++di;
      else if(i == t) ++i, ++j, ++l, ++di;
    }
    return res;
  }
};
