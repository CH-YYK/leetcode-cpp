#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int shipWithinDays(vector<int> &weights, int D) {
    int n = weights.size();
    memo = vector<vector<int>>(n, vector<int>(D+1, -1));
    return dfs(weights, 0, D);
  }
private:
  vector<vector<int>> memo;
  int dfs(vector<int>& weights, int i, int d) {
    if(i == weights.size()) return 0;
    if(d == 1)
      return memo[i][d] = accumulate(weights.begin() + i, weights.end(), 0);
    if(memo[i][d] >= 0) return memo[i][d];
    int res = 1e9, sum = 0;
    for(int j = i; j < weights.size(); ++j) {
      sum += weights[j];
      int other = dfs(weights, j+1, d-1);
      res = min(res, max(sum, other));
    }
    return memo[i][d] = res;
  }
};
