#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> res;
    vector<int> taken(numCourses, 0); // 0: no considered, 1: start considering, 2: finish taking
    stack<int> stk;
    vector<vector<int>> graph(numCourses);
    for (auto pair : prerequisites)
      graph[pair[0]].push_back(pair[1]);

    for (int i = 0; i < numCourses; ++i) {
      if(taken[i] != 0) continue;
      taken[i] = 1;
      stk.push(i);
      while (!stk.empty()) {
        if (graph[stk.top()].empty()) { // no prerequisites
          if(taken[stk.top()] < 2) {  // hasn't been finished
            taken[stk.top()] = 2;
            res.push_back(stk.top());
          }
          stk.pop();
        } else {  // has prerequisites
          int tmp = stk.top();
          taken[tmp] = 1;  // considering course
          while (!graph[tmp].empty()) {
            if(taken[graph[tmp].back()] == 1) // try to take course that rely on current
              return vector<int>();
            if(taken[graph[tmp].back()] == 0) // consider the course that hasn't been considered
              stk.push(graph[tmp].back());
            graph[tmp].pop_back();
          }
        }
      }
    }
    return res;
  }
};
