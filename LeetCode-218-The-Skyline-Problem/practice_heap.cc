#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>> ans;
    int i = 0, len = buildings.size();
    priority_queue<pair<int,int>> pq; // <h, r> maxheap
    int cur_x, cur_h;
    while(i < len || !pq.empty()) {
      // check whether there is an another "overlapped" building
      // add another building in pq if needed
      if(pq.empty() || i < len && buildings[i][0] <= pq.top().second) { // overlapped building
        cur_x = buildings[i][0];
        while(i < len && cur_x == buildings[i][0]) {
          pq.emplace(buildings[i][2], buildings[i][1]);
          i++;
        }
      } else { // no other overlapped building, reached right edge
        cur_x = pq.top().second;
        // get rid of dominated buildings
        while (!pq.empty() && cur_x >= pq.top().second) 
          pq.pop();
      }
      if(pq.empty()) cur_h = 0;
      else cur_h = pq.top().first;

      if(ans.empty() || cur_h != ans.back()[1])
        ans.push_back({cur_x, cur_h});  // get rid of {r, h}s
    }
    return ans;
  }
};
