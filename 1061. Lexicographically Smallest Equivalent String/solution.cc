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
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    // 'a' == 'a'
    // one char can possibly mapped to several chars (like a independent graph)
    // 		in this independent graph, every char is connected with each
    // other we are interested in the char with the least lexical order Union
    // found: clustering 	enumerate
    UnionFind uf(26);
    for (int i = 0; i < s1.size(); ++i) {
      uf.Union(s1[i] - 'a', s2[i] - 'a');
    }
    string res;
    for (char c : baseStr) {
      for (int i = 0; i < 26; ++i) {
        if (uf.Find(i) == uf.Find(c - 'a')) {
          res += 'a' + i;
          break;
        }
      }
    }
    return res;
  }
};

int main() {}
