#include <vector>
using namespace std;

class Solution {
public:
  int maximumInvitations(vector<vector<int>> &grid) {
    m = grid.size(), n = grid[0].size();
    int matches = 0;
    vector<int> paired(n, -1);
    for (int u = 0; u < m; ++u) {
      vector<int> visited(n, 0);
      if (BipartiteMatch(grid, u, visited, paired))
        matches++;
    }
    return matches;
  }

private:
  int m, n;
  /* Try to matche a boy (u) with a girl that hasn't been invited(visited) or paired.
   * Return true -> a girl canbe found
   * Return false -> no girl canbe found
   */
  bool BipartiteMatch(vector<vector<int>> &grid, int u, vector<int> &visited,
                      vector<int> &paired) {
    for (int v = 0; v < n; ++v) {
      if (grid[u][v] == 0 || visited[v])
        continue;

      visited[v] = 1;
      // if the girl[v] hasn't been invited or we can find her mate another girl to pair
      if (paired[v] < 0 || BipartiteMatch(grid, paired[v], visited, paired)) {
        paired[v] = u;
        return true;
      }
    }
    return false;
  }
};

/* Complexity analysis:
 * At least to call BipartiteMatch M times: O(M)
 * In each call of BipartiteMatch, we'll try to pair N girls and keep calling until no more girls can be invited: O(N * N)
 * O(M*N^2)
 */
