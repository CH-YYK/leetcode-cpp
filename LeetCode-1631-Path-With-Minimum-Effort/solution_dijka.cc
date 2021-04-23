#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    const vector<int> dirs{0, -1, 0, 1, 0};
    const int m = heights.size(), n = heights[0].size();
    using Node = pair<int, int>;  // {cost, node}
    vector<int> efforts(m * n, 1e9);  // efforst between 0 to v
    efforts[0] = 0;

    priority_queue<Node, vector<Node>, greater<Node>> q;
    q.emplace(0, 0);

    while(!q.empty()) {
      auto [t, u] = q.top();
      q.pop();
      if(u == m * n - 1) return t;

      int i = u / n, j = u % n;
      for(int d = 0; d < 4; ++d) {
        int ni = i + dirs[d], nj = j + dirs[d+1];
        if(ni < 0 || nj < 0 || ni == m || nj == n)
          continue;
        const int v = ni * n + nj;
        int tmp = max(t, abs(heights[ni][nj], heights[i][j]));
        if(tmp >= efforts[v]) continue;
        // put node v to queue if there is a lower effort found
        // need to update neighbors of v accordingly
        efforts[v] = tmp;
        q.emplace(tmp, v);
      }
    }
    return -1;
  }
private:
  int abs(const int& lhs, const int& rhs) {
    if(lhs < rhs) return rhs - lhs;
    else return lhs - rhs;
  }
};
