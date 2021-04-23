#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

struct cmp{
  bool operator()(vector<long>& lhs, vector<long>& rhs) {
    if(lhs[0] < rhs[0]) return false;
    else if(lhs[0] == rhs[0]) return lhs[1] > rhs[1];
    else return true;
  }
    };

class Solution {
public:
  vector<int> getOrder(vector<vector<int>> &tasks) {
    using Task = vector<long>;
    priority_queue<Task, vector<Task>, cmp> q;

    for(int i = 0; i < tasks.size(); ++i)
      tasks[i].push_back(i);
    sort(tasks.begin(), tasks.end());
    
    q.push({tasks[0][1], tasks[0][2], tasks[0][0]});
    int i = 1;
    while(i < tasks.size() && tasks[i][0] == tasks[i-1][0])
      q.push({tasks[i][1], tasks[i][2], tasks[i][0]}), i++;

    long startTime, endTime = 0;
    vector<int> res;
    while(i < tasks.size() || !q.empty()) {
      while(!q.empty()) {
        Task vec = q.top();
        q.pop();
        long p = vec[0];
        int index = vec[1];

        startTime = max(endTime, vec[2]);
        endTime = startTime + p;

        res.push_back(index);

        while(i < tasks.size() && tasks[i][0] <= endTime)
          q.push({tasks[i][1], tasks[i][2], tasks[i][0]}), i++;
      }
      if(i < tasks.size())
        q.push({tasks[i][1], tasks[i][2], tasks[i][0]}), i++;
    }
    return res;
  }
};
