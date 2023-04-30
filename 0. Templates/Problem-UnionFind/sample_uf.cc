#include <vector>

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