#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int countUnguarded(int m, int n, vector<vector<int>> &guards,
                     vector<vector<int>> &walls) {
    // A typical BFS problem. Starting from each guard, navigate in all 4
    // directions, no turning, and stop until hitting a wall. Count the cells
    // that were guarded, and the rest are the unguarded cells.
    //
    // The 4 directions are represented by 4 bits in an integer.
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (auto &wall : walls)
      grid[wall[0]][wall[1]] = (1 << 2);
    for (auto &guard : guards)
      grid[guard[0]][guard[1]] = (1 << 2);
    queue<pair<int, int>> q;
    // Initialize 4 directions from each guard.
    // loc = r * n + c
    // dir = -n, 1, n, -1 for up, right, down, left (bits: 0, 1, 2, 3)
    for (auto &guard : guards) {
      int loc = guard[0] * n + guard[1];
      q.push({loc, -n});
      q.push({loc, 1});
      q.push({loc, n});
      q.push({loc, -1});
    }
    int unguarded = m * n - guards.size() - walls.size();
    while (!q.empty()) {
      auto [loc, dir] = q.front();
      q.pop();
      int r = loc / n, c = loc % n;
      int next_r = r + dir / n, next_c = c + dir % n;
      if (next_r < 0 || next_r == m || next_c < 0 || next_c == n)
        continue;
      int dir_bit = 1 << (abs(dir) == n ? 0 : 1);
      if (grid[next_r][next_c] == (1 << 2))
        continue;
      if ((grid[next_r][next_c] & dir_bit) > 0)
        continue;
      if (grid[next_r][next_c] == 0)
        --unguarded;
      grid[next_r][next_c] |= dir_bit;
      q.push({next_r * n + next_c, dir});
    }
    return unguarded;
  }
};

