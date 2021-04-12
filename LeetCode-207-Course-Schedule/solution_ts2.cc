#include <vector>
using namespace std;

/* Check whether there is a cycle in the graph
 * If this is a cycle at index i then there is a scenario
 *  * it has started searching from i and get back to i during searching
 * visited[i] == 0 : hasn't started searching from i
 * visited[i] == 1 : already started iterating from i
 * visited[i] == 2 : finished searching nodes in the subgraph expanded from i
 */
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> grid(numCourses);
    for (auto pair : prerequisites)
      grid[pair[0]].push_back(pair[1]);
    visited = vector<int>(numCourses, 0);
    for (int i = 0; i < numCourses; ++i) {
      if (isCycle(grid, i))
        return false;
    }
    return true;
  }

private:
  vector<int> visited; // 0: no visit, 1: visiting. 2, visited
  bool isCycle(vector<vector<int>> &grid, int i) {
    if (visited[i] == 2)  // subgraph has been searched
      return false;
    if (visited[i] == 1)  // subgraph hasn't been finishd searching and encounter cycle
      return true;

    visited[i]++;  // visied[i] = 1; start searching the subgraph from nodei
    for (int next : grid[i]) {
      if (isCycle(grid, next))
        return true;
    }
    visited[i]++;  // visited[i] = 2; finish searching the subgraph from nodei
    return false;
  }
};
