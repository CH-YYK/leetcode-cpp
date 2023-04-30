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

class UnionFind {
public:
  UnionFind(int n) {
    ranks_ = vector<int>(n+1, 0);
    parents_ = vector<int>(n+1, 0);

    for(int i = 0; i < n; ++i)
      parents_[i] = i; // initialize each to itself
  }
  int Find(int u) {
    if(u != parents_[u])
      parents_[u] = Find(parents_[u]);
    return parents_[u];
  }
  bool Union(int u, int v) { // can union?
    int pu = Find(u);
    int pv = Find(v);

    if(pu == pv) return false;

    if(ranks_[pv] > ranks_[pu])
      parents_[pu] = pv;
    else if(ranks_[pv] < ranks_[pu])
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    	if(source == destination) return true;
    	UnionFind uf(n);
    	for(vector<int>& edge : edges) {
    		uf.Union(edge[0], edge[1]);
    		if(uf.Find(source) == uf.Find(destination))
    			return true;
    	}
    	return false;
    }
};