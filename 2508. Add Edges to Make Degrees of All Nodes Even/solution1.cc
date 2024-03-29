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

class Solution {
 public:
  bool isPossible(int n, vector<vector<int>>& edges) {
    // no self-loops and no repeated
    // add inner connections to nodes with odd degrees

    // preprocessing
    vector<int> outdegrees(n + 1, 0);
    for (vector<int>& edge : edges) {
      outdegrees[edge[0]]++;
      outdegrees[edge[1]]++;
    }
    vector<int> oddDegrees, evenDegrees;
    for (int i = 1; i < outdegrees.size(); ++i)
      if (outdegrees[i] & 1)
        oddDegrees.push_back(i);
      else
        evenDegrees.push_back(i);

    // case: 0,1,3
    if (oddDegrees.size() & 1) return false;
    if (oddDegrees.size() == 0) return true;

    // case 2
    if (oddDegrees.size() == 2) {
      int a = oddDegrees[0], b = oddDegrees[1];
      unordered_map<int, unordered_set<int>> mp;
      for (vector<int>& edge : edges) {
        if (edge[0] == a) mp[a].insert(edge[1]);
        if (edge[1] == a) mp[a].insert(edge[0]);
        if (edge[0] == b) mp[b].insert(edge[1]);
        if (edge[1] == b) mp[b].insert(edge[0]);
      }
      if (!mp[a].count(b)) return true;
      // can find a common node to connect
      for (int node : evenDegrees) {
        if (!mp[a].count(node) && !mp[b].count(node)) return true;
      }
      return false;
    }

    // case: 4
    if (oddDegrees.size() == 4) {
      int a = oddDegrees[0], b = oddDegrees[1], c = oddDegrees[2],
          d = oddDegrees[3];
      unordered_map<int, unordered_set<int>> mp;
      unordered_set<int> s = {a, b, c, d};
      for (vector<int>& edge : edges)
        if (s.count(edge[0]) && s.count(edge[1])) {
          mp[edge[0]].insert(edge[1]);
          mp[edge[1]].insert(edge[0]);
        }
      for (auto val : mp)
        if (val.second.size() > 2) return false;

      // [a,b c,d], [a,c, b,d], [a,d b,c]
      if (!mp[a].count(b) && !mp[c].count(d)) return true;
      if (!mp[a].count(c) && !mp[b].count(d)) return true;
      if (!mp[a].count(d) && !mp[b].count(c)) return true;
      return false;
    }
    // case: >4
    return false;
  }
};