#include <algorithm>
#include <map>
#include <utility>
#include <vector>

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
    vector<int> dp(n+1, 0);
    // dp[i]: max profit before endTime[i-1], dp[0] = 0
    //   do the jobs[i-1] -> dp[j] + jobs[i-1][2]
    //   skip the jobs[i-1] -> dp[i-1]

    for(int i = 1; i <= n; ++i) {
      int j = i;
      while(j > 0 && jobs[j-1][0] > jobs[i-1][1]) --j;
      int cur = dp[j] + jobs[i-1][2];
      dp[i] = max(cur, dp[i-1]);
    }
    return dp.back();
  }
};
