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

    for (int i = 0; i < n; ++i) parents_[i] = i;  // initialize each to itself
  }
  int Find(int u) {
    if (u != parents_[u]) parents_[u] = Find(parents_[u]);
    return parents_[u];
  }
  bool Union(int u, int v) {  // can union?
    int pu = Find(u);
    int pv = Find(v);

    if (pu == pv) return false;

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
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                         vector<vector<int>>& queries) {
    //
    // Suppose only one query is passed in [p1, p2, limit2]
    // 1. dfs/bfs from pi until pj, and find the minimum limit
    // 2. Union find to see is there a edge (< limit) can make pi and pj
    // connected
    //
    // a. sort queries by limit in ascending order
    // b. sort edgeList by distance in ascending order
    // c. adding edges to Union Find and checking pi,pj at the front of queries
    // 		c-1: if edge distance start become greater than limit, pop it and
    // set false 		c-2: if pi and pj are connected, pop it and set
    // true
    UnionFind uf(n);
    for (int i = 0; i < queries.size(); ++i) queries[i].push_back(i);
    // ascending edge distance
    sort(edgeList.begin(), edgeList.end(),
         [](vector<int>& lhs, vector<int>& rhs) { return lhs[2] < rhs[2]; });
    // descending limit
    sort(queries.begin(), queries.end(),
         [](vector<int>& lhs, vector<int>& rhs) { return lhs[2] > rhs[2]; });

    int maxDistance = -1;
    vector<bool> answers(queries.size());
    for (int i = 0; i < edgeList.size(); ++i) {
      if (queries.empty()) return answers;

      // added edges are all smaller than limits in the queries
      // flush out those non applicable queries
      maxDistance = edgeList[i][2];
      while (!queries.empty() && maxDistance >= queries.back()[2]) {
        bool state = uf.Find(queries.back()[0]) == uf.Find(queries.back()[1]);
        answers[queries.back()[3]] = state;
        queries.pop_back();
      }
      uf.Union(edgeList[i][0], edgeList[i][1]);
    }

    while (!queries.empty()) {
      bool state = uf.Find(queries.back()[0]) == uf.Find(queries.back()[1]);
      state &= maxDistance < queries.back()[2];
      answers[queries.back()[3]] = state;
      queries.pop_back();
    }
    return answers;
  }
};

int main() {}
