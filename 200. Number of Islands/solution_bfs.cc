#include <vector>
#include <queue>
#include <utility>

using namespace std;
/* Space complexity of BFS: O(min(M, N))
 */
class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    int nisland = 0;
    int m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == '0' || grid[i][j] == '2')
          continue;
        q.push({i, j});
        while (!q.empty()) {
          int a = q.front().first;
          int b = q.front().second;
          q.pop();
          if (a < 0 || a == m)
            continue;
          if (b < 0 || b == n)
            continue;
          if (grid[a][b] == '0' || grid[a][b] == '2')
            continue;
          grid[a][b] = '2';
          q.push({a - 1, b});
          q.push({a + 1, b});
          q.push({a, b - 1});
          q.push({a, b + 1});
        }
        nisland++;
      }
    }
    return nisland;
  }
};
