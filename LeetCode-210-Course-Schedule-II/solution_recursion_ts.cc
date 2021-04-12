#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    graph = vector<vector<int>>(numCourses);
    for (auto pair : prerequisites)
      graph[pair[0]].push_back(pair[1]);
    vector<int> res;
    taken = vector<int>(numCourses, 0);
    for (int i = 0; i < numCourses; ++i)
      dfs(i, res);
    return iscycle ? vector<int>() : res;
  }

private:
  vector<vector<int>> graph;
  vector<int> taken;
  bool iscycle = false;
  void dfs(int i, vector<int> &res) {
    if (taken[i] == 2)
      return;
    if (taken[i] == 1) {
      iscycle = true;
      return;
    }
    taken[i] = 1;
    for (int num : graph[i]) {
      dfs(num, res);
    }
    taken[i] = 2;
    res.push_back(i);
    return;
  }
};
