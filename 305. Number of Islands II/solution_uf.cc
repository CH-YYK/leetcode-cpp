#include <vector>
#include <unordered_set>
using namespace std;

class UnionFind {
public:
  UnionFind(int m, int n) {
    parents_ = vector<int>(m * n, -1);
    ranks_ = vector<int>(m*n, 0);
  }

  int Find(int u) {
    if(u != parents_[u])
      parents_[u] = Find(parents_[u]);
    return parents_[u];
  }

  bool Union(int u, int v) {  // merge parents and erase the old fron set
    int pu = Find(u);
    int pv = Find(v);

    if(pu == pv) return false;

    if(ranks_[pu] > ranks_[pv])
      parents_[pv] = pu, s.erase(pv);
    else if(ranks_[pu] < ranks_[pv])
      parents_[pu] = pv, s.erase(pu);
    else {
      parents_[pv] = pu, s.erase(pv);  // merge v to u if u and v have equal ranks
      ranks_[pu] += 1;
    }
    return true;
  }
  // ---------- helper functions ----------
  int nParents() {
    return s.size();
  }
  int getNode(int pos) {
    return parents_[pos] >= 0;
  }
  void initNode(int pos) {
    parents_[pos] = pos;
    s.insert(pos);
  }
private:
  vector<int> ranks_;
  vector<int> parents_;
  unordered_set<int> s; // distinct parents;
};

class Solution {
public:
  vector<int> numIslands2(int m, int n, vector<vector<int>> &positions) {
    UnionFind uf(m, n);
    vector<int> res;
    for(auto pair : positions) {
      int i = pair[0];
      int j = pair[1];

      int pos = i * n + j;
      uf.initNode(pos);
      if(i - 1 >= 0 && uf.getNode(pos - n))
        uf.Union(pos-n, pos);
      if(i + 1 < m && uf.getNode(pos+n))
        uf.Union(pos + n, pos);
      if(j - 1 >= 0 && uf.getNode(pos - 1))
        uf.Union(pos - 1, pos);
      if(j + 1 < n && uf.getNode(pos + 1))
        uf.Union(pos + 1, pos);
      res.push_back(uf.nParents());
    }
    return res;
  }
};
