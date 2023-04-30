#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<int> topological_sorting(vector<vector<int>>& edges, int n) {
    // edges[i] = [5, 4] which is  "5 -> 4"
    // visited[i] = true: been visited
    // use stack to go through the graph as well as dfs.
    //   1. "dfs" doesn't need dependencies.
    //   2. "topological sorting" can only visit a node after its dependencies.
    //   3. "visited" track the states of nodes and "stack" stores the nodes to be visited.
    //   4. visit a nodes (pop from stack) after "deps" have been visited;



    // suppose there's no inner-cycle.
    vector<vector<int>> graph(n);
    vector<int> visited(n, 0);
    vector<int> res;

    int tmp;
    bool ready = true;

    for(auto& edge : edges) // dep matrix: graph[i][j]: i depends on j
      graph[edge[1]].push_back(edge[0]);

    stack<int> _stack;
    for(int st = 0; st < n; ++st) {
      if(visited[st]) continue;

      _stack.push(st);
      while(!_stack.empty()) {

        // current node to visit
        tmp = _stack.top();

        ready = true;
        for(int &next : graph[tmp])  // if all deps have been visited.
          if(visited[next]) continue;
          else {
            _stack.push(next);   // to be visited
            ready = false;
          }
        if(ready)  // set "tmp" as visited and pop from stack.
          _stack.pop(), res.push_back(tmp), visited[tmp]++;
      }
    }
  return res;
  }
};


int main() {
  vector<vector<int>> _edges = {
    {5, 2}, {5, 0},
    {4, 0}, {4, 1},
    {2, 3}, {3, 1},
  };

  vector<int> res = Solution().topological_sorting(_edges, 6);
  for(int i : res) 
    cout << i << " ";

}
