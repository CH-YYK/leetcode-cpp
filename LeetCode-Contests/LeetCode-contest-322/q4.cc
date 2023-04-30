// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class UnionFind {
public:
  UnionFind(int n) {
    ranks_ = vector<int>(n + 1, 0);
    parents_ = vector<int>(n + 1, 0);

    for (int i = 0; i < n; ++i)
      parents_[i] = i; // initialize each to itself
  }
  int Find(int u) {
    if (u != parents_[u])
      parents_[u] = Find(parents_[u]);
    return parents_[u];
  }
  bool Union(int u, int v) { // can union?
    int pu = Find(u);
    int pv = Find(v);

    if (pu == pv)
      return false;

    if (ranks_[pv] > ranks_[pu])
      parents_[pu] = pv;
    else if (ranks_[pv] < ranks_[pu])
      parents_[pv] = pu;
    else {
      parents_[pv] = pu;
      ranks_[pu] += 1;
    }
    return true;
  }

private:
  vector<int> ranks_;
  vector<int> parents_;
};

class Solution {
public:
  int magnificentSets(int n, vector<vector<int>> &edges) {
    // two connected nodes cannot be in one group
    // if a and b connected to c, a and b should be in the group
    //  that is adjacent to c
    //
    // If c is in group m, then a and b can be in either m - 1 or m + 1
    // let's decrease the complexity by force the group index to increase only
    // and we must find a root first
    //
    // We can perform the BFS on every node to find a solution but that would be
    // O((N + E)*N). Given that nodes are not fully connected, use union find to
    // find all components and perform BFS respectively
    //

    vector<vector<int>> graph(n);

    UnionFind uf(n);
    unordered_map<int, vector<int>> components;

    for (vector<int> &edge : edges) {
      graph[edge[0] - 1].push_back(edge[1] - 1);
      graph[edge[1] - 1].push_back(edge[0] - 1);
      uf.Union(edge[0] - 1, edge[1] - 1);
    }

    for (int i = 0; i < n; ++i) {
      components[uf.Find(i)].push_back(i);
    }

    function<int(int)> bfs = [&](int root) {
      // the group index should match the depth from root
      queue<int> q;
      q.push(root);
      vector<int> depths(n, -1);
      int depth = 0;
      depths[root] = 0;

      while (!q.empty()) {
        int size = q.size();
        while (size--) {
          int curr = q.front();
          q.pop();
          for (int nxt : graph[curr]) {
            if (depths[nxt] >= 0 && abs(depth - depths[nxt]) != 1)
              return -1;
            else if (depths[nxt] >= 0)
              continue;
          	depths[nxt] = depth + 1;
            q.push(nxt);
          }
          depths[curr] = depth;
        }
        depth++;
      }
      return depth;
    };

    int res = 0;
    for (auto& [val, nodes] : components) {
      int depth = -1;
      for (int i : nodes)
        // depth = max(depth, bfs(i, graph, n));
        depth = max(depth, bfs(i));
      if (depth == -1)
        return -1;
      else
        res += depth;
    }
    return res;
  }
};

int main() {}
