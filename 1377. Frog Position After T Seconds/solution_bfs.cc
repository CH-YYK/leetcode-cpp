#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
    vector<vector<int>> graph(n);
    for (auto edge : edges) {
      graph[edge[0] - 1].push_back(edge[1] - 1);
      graph[edge[1] - 1].push_back(edge[0] - 1);
    }
    queue<vector<int>> q;

    q.push({0, 1, -1}); // node=1, denom=1
    while (t >= 0 && !q.empty()) {
      int size_ = q.size();
      for (int i = 0; i < size_; ++i) {
        int node = q.front()[0], denom = q.front()[1], parent = q.front()[2];
        q.pop();
        int m = graph[node].size();
        
        if(t == 0 && node == target - 1) return 1.0 / denom;  // we are at the t-th step
        if(node == target - 1 && m == 1 && parent != -1) return 1.0 / denom;  // target is root
        if(node == target - 1 && m == 0 && parent == -1) return 1.0 / denom;  // target is terminal

        for (int next : graph[node]) {
          if (next == parent) {
            m--;
            continue;
          }
          q.push({next, denom * m, node});
        }
      }
      t--;
    }
    return 0;
  }
};
