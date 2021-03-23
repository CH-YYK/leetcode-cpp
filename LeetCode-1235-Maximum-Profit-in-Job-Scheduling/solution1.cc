#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime,
                    vector<int> &profit) {
    n = startTime.size();
    memo = vector<int>(n, -1);
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; ++i)
      jobs.emplace_back(startTime[i], i);
    sort(jobs.begin(), jobs.end());
    return maxprofit(jobs, endTime, profit, 0);
  }

private:
  int n = 0;
  vector<int> memo;
  int maxprofit(vector<pair<int, int>> &starts, vector<int> &endTime,
                vector<int> &profit, int i) {
    if (i == n)
      return 0;
    if (memo[i] >= 0)
      return memo[i];

    int max_ = 0;
    for (int j = i; j < n; ++j) {
      int p = profit[starts[j].second];
      int end = endTime[starts[j].second];

      int k = j;
      while (k < n && starts[k].first < end)
        ++k;
      max_ = max(max_, maxprofit(starts, endTime, profit, k) + p);
    }
    return memo[i] = max_;
  }
};
