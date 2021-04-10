#include <vector>
using namespace std;

class Solution {
public:
  int maximumInvitations(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    invited = vector<int>(n, 0);
    return dfs(grid, 0);
  }

private:
  vector<int> invited;
  int dfs(vector<vector<int>> &grid, int b) {
    if (b == grid.size()) {
      return 0;
    }
    int max_ = 0;
    for (int i = 0; i < grid[b].size(); ++i) {
      if (grid[b][i] == 1 && invited[i] == 0) {
        invited[i] = 1;
        max_ = max(max_, dfs(grid, b + 1) + 1);
        invited[i] = 0;
      }
      if (max_ == 0)
        max_ = dfs(grid, b + 1);
    }
    return max_;
  }
};
