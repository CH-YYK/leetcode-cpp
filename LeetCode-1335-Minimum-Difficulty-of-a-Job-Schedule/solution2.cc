#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int minDifficulty(vector<int> &jobDifficulty, int d) {
    int n = jobDifficulty.size();
    if (n < d)
      return -1;
    return dfs(jobDifficulty, 0, d);
  }

private:
  int dfs(vector<int> &jobs, int i, int j) {
    // minimum difficulty to partition jobs[i:] in j days
    if (i == jobs.size() - 1)
      return jobs[i];
    if (j == 1) {
      return *max_element(jobs.begin() + i, jobs.end());
    }
    int min_ = INT_MAX;
    int curmax = 0;

    // leave (j-1) numbers to be partitioned by (j-1) at least
    for (int k = i; k < jobs.size() - (j - 1); ++k) {
      curmax = max(curmax, jobs[k]);
      min_ = min(min_, dfs(jobs, k + 1, j - 1) + curmax);
    }
    return min_;
  }
};
