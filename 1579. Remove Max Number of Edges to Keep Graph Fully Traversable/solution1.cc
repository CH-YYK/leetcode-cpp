// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <cmath>
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

/*
ios_base::sync_with_stdio(0);
cin.tie(NULL);
*/

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
  int CountGroups(int st) {
    unordered_set<int> s;
    for (int i = st; i < parents_.size(); ++i) s.insert(Find(i));
    return s.size();
  }

 private:
  vector<int> ranks_;
  vector<int> parents_;
};

class Solution {
 public:
  int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    UnionFind ufa(n), ufb(n);
    int ans = 0;

    // consider type 3 first
    for (vector<int>& edge : edges) {
      int type = edge[0];
      int u = edge[1];
      int v = edge[2];
      if (type < 3) continue;
      if (type == 3) {
        if (ufa.Find(u) == ufa.Find(v) || ufb.Find(u) == ufb.Find(v)) {
          ans++;
          continue;
        }
        ufa.Union(u, v);
        ufb.Union(u, v);
      }
    }
    for (vector<int>& edge : edges) {
      int type = edge[0];
      int u = edge[1];
      int v = edge[2];
      if (type == 1) {
        if (ufa.Find(u) == ufa.Find(v)) {
          ans++;
          continue;
        }
        ufa.Union(u, v);
      }
      if (type == 2) {
        if (ufb.Find(u) == ufb.Find(v)) {
          ans++;
          continue;
        }
        ufb.Union(u, v);
      }
    }

    if (ufa.CountGroups(1) > 1 || ufb.CountGroups(1) > 1) return -1;
    return ans;
  }
};