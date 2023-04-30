#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {
    int n = startTime.size();
    vector<int> dp(n, 0);  // dp[i]: maximum profit earned after working on job[i]
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; ++i)
      jobs.emplace_back(startTime[i], i);
    sort(jobs.begin(), jobs.end());
    dp[0] = jobs[0].begin();

    for(int i = 1; i < n; ++i) {
      int p = profit[jobs[i].second];
      dp[i] = p;
      for(int j = 0; j < i; ++j) {
        int k = jobs[j].second;
        if(jobs[i].first >= endTime[k])  // compare current starttime and other endtimes
          dp[i] = max(dp[i], dp[j] + p);
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};
