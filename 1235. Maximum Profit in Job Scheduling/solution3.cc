#include <algorithm>
#include <utility>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {
    int n = startTime.size();
    vector<vector<int>> jobs;
    for (int i = 0; i < n; ++i)
      jobs.push_back({endTime[i], startTime[i], profit[i]});
    sort(jobs.begin(), jobs.end());
    // reduce to a 01 knapack problem with W as time and V as profit
    // map[t]: maximum profit obtained after time t
    // (when considering element, dp stores element-wise cumulative states)
    map<int, int> dp = {{0,0}};  //key: time, value: profit

    for(auto& job : jobs){
      // binary search the last endtime <= starttime
      // upper_bound(val) -> num > val
      // lower_bound(val) -> num >= val
      // prev(upper_bound(val)) -> num <= val
      int cur = prev(dp.upper_bound(job[1]))->second + job[2];
      if(cur > dp.rbegin()->second)
        dp[job[0]] = cur;
    }
    return dp.rbegin()->second;
  }
};
