#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
  int minDifficulty(vector<int> &jobDifficulty, int d) {
    int n = jobDifficulty.size();
    if(n < d) return -1;
    memo = vector<vector<int>>(n + 1, vector<int>(d+1, -1));
    return dfs(jobDifficulty, 0, d);
  }

private:
  vector<vector<int>> memo;
  /* i take [0, jobs.size()], j take [0, d]
   */
  int dfs(vector<int> &jobs, int i, int j) {
    // minimum difficulty to partition jobs[i:] in j days
    if (i == jobs.size() - 1)
      return jobs[i];
    if (j == 1) {
      return *max_element(jobs.begin() + i, jobs.end());
    }

    if(memo[i][j] >= 0) return memo[i][j];

    int min_ = INT_MAX;
    int curmax = 0;
    for (int k = i; k < jobs.size() - (j-1); ++k) {
      curmax = max(curmax, jobs[k]);
      min_ = min(min_, dfs(jobs, k + 1, j - 1) + curmax);
    }
    memo[i][j] = min_;
    return min_;
  }
};
