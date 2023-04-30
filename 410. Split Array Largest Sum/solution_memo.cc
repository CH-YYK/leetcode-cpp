#include <vector>
#include <algorithm>
using namespace std;

/*
 * O(N^2*M)
 */
class Solution {
public:
  int splitArray(vector<int> &nums, int m) {
    int n = nums.size();
    memo = vector<vector<int>> (n, vector<int>(m + 1, -1));
    return dfs(nums, 0, m);
  }
private:
  vector<vector<int>> memo;
  int dfs(vector<int>& nums, int i, int m) {
    if(i == nums.size()) return 0;
    if(m == 1)
      return accumulate(nums.begin() + i, nums.end(), 0);
    if(memo[i][m] >= 0) return memo[i][m];
    int res = INT_MAX, sum = 0;
    for(int j = i; j < nums.size(); ++j) {
      sum += nums[j];
      res = min(res, max(sum, dfs(nums, j+1, m-1)));
    }
    return memo[i][m] = res;
  }
};
