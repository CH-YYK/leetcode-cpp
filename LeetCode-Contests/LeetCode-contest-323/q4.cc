// Hello, this is a CPP leetcode snippet.

#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <set>
#include <map>
#include <sstream>

using namespace std;

int main() {
    
}

class Solution {
 public:
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    // The points of a queries[i] depends on how many cells in the grid it can
    // arrive a cell can be arrived by queries[i] iff there is a path whose max
    // value is < queries[i] run a BFS with Dijkstra to get minimum max for each
    // cell in the grid
    int m = grid.size(), n = grid[0].size();
	// path maximums for each cell
    vector<vector<int>> maxes(m, vector<int>(n, INT_MAX));
    maxes[0][0] = 0;
	// max heap, save negative value to make it min heap
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 0);

    while (!pq.empty()) {
      auto [max_, loc] = pq.top();
      pq.pop();

      int i = loc / n;
      int j = loc % n;
      max_ = max(-max_, grid[i][j]);
      for (int d = 0; d < 4; ++d) {
        int ni = i + dirs[d];
        int nj = j + dirs[d + 1];
        if (ni < 0 || nj < 0 || ni == m || nj == n) continue;
        if (max_ >= maxes[ni][nj]) continue;
        pq.emplace(-max_, ni * n + nj);
        maxes[ni][nj] = max_;
      }
    }
	
	// sort the query value and perform prefix sum
    map<int, int> mp;
    for (int num : queries) mp[num] = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        auto it = mp.upper_bound(max(maxes[i][j], grid[i][j]));
        if (it != mp.end()) it->second++;
      }
	
	// query the result of prefix sum for each queries[i]
    vector<int> answers(queries.size());
    auto prev = mp.begin();
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      if (it != mp.begin()) 
        it->second += prev->second;
      prev = it;
    }
    for (int i = 0; i < answers.size(); ++i) answers[i] = mp[queries[i]];
    return answers;
  }
 private:
  vector<int> dirs = {-1, 0, 1, 0, -1};
};