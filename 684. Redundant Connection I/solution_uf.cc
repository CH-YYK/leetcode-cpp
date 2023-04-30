#include <vector>

using namespace std;

class UnionFindSet{
public:
  UnionFindSet(int n) {
    ranks_ = vector<int>(n+1, 0);
    parents_ = vector<int>(n+1, 0);

    for(int i = 0; i < parents_.size(); ++i)
      parents_[i] = i;  // initialize each to self
  }

  // merge low rank tree to higher rank one
  // union v to u; if(u == v)
  bool Union(int u, int v) {
    int pu = Find(u);
    int pv = Find(v);

    if(pu == pv) return false;  // false as they have already been unioned

    if(ranks_[pv] > ranks_[pu])
      parents_[pu] = pv;
    else if(ranks_[pu] > ranks_[pv])
      parents_[pv] = pu;
    else {
      parents_[pv] = pu;
      ranks_[pu] += 1;  // update ranks
    }
    return true;
  }
  // Get the root of u
  int Find(int u) {
    if(u != parents_[u])  // end when current is root
      parents_[u] = Find(parents_[u]);  // compress the path
    return parents_[u];
  }
private:
  vector<int> ranks_;
  vector<int> parents_;
};

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    UnionFindSet uf(n+1);
    for(auto e : edges) {
      if(!uf.Union(e[0], e[1])) return e;
    }
    return {};
  }
};
