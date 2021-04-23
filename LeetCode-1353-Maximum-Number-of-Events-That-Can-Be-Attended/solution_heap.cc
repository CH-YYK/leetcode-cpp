#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// TC: O(nlogn)
struct event_cmp {
  bool operator()(vector<int> &lhs, vector<int> &rhs) {
    if (lhs[1] > rhs[1])
      return true;
    else
      return false;
  }
};

class Solution {
public:
  int maxEvents(vector<vector<int>> &events) {
    const int n = events.size();
    sort(events.begin(), events.end());
    using Event = vector<int>;
    priority_queue<Event, vector<Event>, event_cmp> q;
    q.push(events[0]);
    int d = q.top()[0], i = 1, res = 0;
    while (i < n && events[i][0] == d)
      q.push(events[i++]);

    while (i < n || !q.empty()) {
      if (i < n && q.empty()) {
        q.push(events[i++]);
        d = q.top()[0];
      }
      while (i < n && d == events[i][0])
        q.push(events[i++]);

      while (!q.empty() && q.top()[1] < d)
        q.pop();
      if (!q.empty()) {
        q.pop();
        res++;
      }
      d++;
    }
    return res;
  }
};
