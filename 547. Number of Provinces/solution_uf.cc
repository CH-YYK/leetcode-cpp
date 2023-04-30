#include <vector>

using namespace std;

class UnionFindSet {
public:
  UnionFindSet(int n) {
    ranks_ = vector<int>(n+1, 0);
    parents_ = vector<int>(n+1, 0);

    for(int i = 0; i < parents_.size(); ++i)
      parents_[i] = i;
  }
  bool Union(int u, int v) {
    int pu = Find(u);
    int pv = Find(v);

    if(pu == pv) return false;  // u and v were in same set

    if(ranks_[pv] > ranks_[pu])
      parents_[pu] = pv;
    else if(ranks_[pv] < ranks_[pu])
      parents_[pv] = pu;
    else {
      parents_[pv] = pu;
      ranks_[pu] += 1;
    }
    return true;  // u and v were in different sets
  }

  int Find(int u) {
    if(u != parents_[u])
      parents_[u] = Find(parents_[u]);
    return parents_[u];
  }

private:
  vector<int> ranks_;
  vector<int> parents_;
};

class Solution {
public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size();
    int res = 1;  // number of sets
    UnionFindSet uf(n+1);

    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j) {
        if(isConnected[i][j] == 0) continue;
        uf.Union(i+1, j+1);
      }
    for(int i = 1; i < n; ++i)
      if(uf.Union(i, i+1)) res++;
    return res;
  }
};
