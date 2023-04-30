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
#include <cmath>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/
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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    	// UnionFind
    	// let's see if two nodes of one value connected in a subgraph?
    	// nodes in one "connected component" are connected 
	   	int n = vals.size();
	   	graph = vector<vector<int>>(n);
	   	for(vector<int>& edge : edges) {
	   		graph[edge[0]].push_back(edge[1]);
	   		graph[edge[1]].push_back(edge[0]);
	   	}

	   	UnionFind uf(n);
	   	int ans = 0;
	   	map<int, vector<int>> valuesToNode;
	   	for(int i = 0; i < n; ++i)
	   		valuesToNode[vals[i]].push_back(i);

	   	for(auto& [val, nodes] : valuesToNode) {
	   		for(int i : nodes) {
	   			// i as a root
	   			for(int j : graph[i])
	   				if(vals[j] <= vals[i])
		   				uf.Union(i, j);		   		
	   		}

	   		unordered_map<int,int> groups;
	   		for(int i : nodes) 
	   			groups[uf.Find(i)]++;
	   		for(auto [_, size] : groups)
	   			ans += size * (size + 1) / 2;
	   	}
	   	return ans;
    }
private:
	vector<vector<int>> graph;
};