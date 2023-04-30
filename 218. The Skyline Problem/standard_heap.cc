#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    vector<vector<int>> ans;
    priority_queue<pair<int,int>> pq;  // <h, r>, maxheap, highest & rightmost
    int i = 0, len = buildings.size();
    int cur_x, cur_h;
    while(i < len || !pq.empty()) {
      if(pq.empty() || i < len && buildings[i][0] <= pq.top().second) { // current building is left to the highest one
        cur_x = buildings[i][0];
        while(i < len && cur_x == buildings[i][0]) {
          pq.emplace(buildings[i][2], buildings[i][1]); // take over the current highest if 
          ++i;
        }
      }else {
        cur_x = pq.top().second;
        while(!pq.empty() && cur_x >= pq.top().second)
          pq.pop();
      }
      cur_h = pq.empty() ? 0 : pq.top().first;
      if(ans.empty() || cur_h != ans.back()[1])
        ans.push_back({cur_x, cur_h});
    }
    return ans;
  }
};
