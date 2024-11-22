#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int countUnguarded(int m, int n, vector<vector<int>> &guards,
                     vector<vector<int>> &walls) {
    // Since the directions from guard are fixed during traversing.
    // We can initiate traversing from each guard, and all the way to another
    // guard or the wall.
    //
    // The main cost to avoid is when multiple guards are on one column or row.
    // The method below save this cost but may have to re-traverse the routes
    // between two guards. Compared to the cost on using queues (enqueue &
    // dequeue), this approach is more simple and efficient.
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (auto &wall : walls)
      grid[wall[0]][wall[1]] = 2;
    for (auto &guard : guards)
      grid[guard[0]][guard[1]] = 2;

    vector<int> dirs = {-1, 0, 1, 0, -1};
    for (auto &guard : guards) {
      for (int d = 0; d < 4; ++d) {
        int r = guard[0], c = guard[1];
        int dr = dirs[d], dc = dirs[d + 1];
        while (r + dr >= 0 && r + dr < m && c + dc >= 0 && c + dc < n &&
               grid[r + dr][c + dc] < 2) {
          r += dr;
          c += dc;
          grid[r][c] = 1;
        }
      }
    }
    int unguarded = 0;
    for (auto &row : grid)
      for (auto &cell : row)
        if (cell == 0)
          ++unguarded;
    return unguarded;
  }
};
