#include <vector>

using namespace std;

class Solution {
public:
  bool hasPath(vector<vector<int>> &maze, vector<int> &start,
               vector<int> &destination) {
    m = maze.size(), n = maze[0].size();
    return dfs(maze, start[0] * n + start[1], destination[0] *n + destination[1]);
  }
private:
  int m, n;
  vector<int> dirs = {0, 1, 0, -1, 0};
  bool dfs(vector<vector<int>>& maze, int start, int destination) {
    // dfs is called when the ball stopped and try other directions
    // never go back
    if(start == destination) return true;

    int i = start / n, j = start % n;
    int curr = maze[i][j];
    maze[i][j] = 2;
    for(int d = 0; d < 4; ++d) {
      int di = dirs[d], dj = dirs[d+1];
      int ni = i + di, nj = j + dj;
      while(!(ni == m || nj == n || ni < 0 || nj < 0 || maze[ni][nj] == 1))
        ni += di, nj += dj;
      ni -= di, nj -= dj;
      if(maze[ni][nj] == 2) continue;
      if(dfs(maze, ni * n + nj, destination)) return true;
    }
    // maze[i][j] = curr;
    return false;
  }
};
