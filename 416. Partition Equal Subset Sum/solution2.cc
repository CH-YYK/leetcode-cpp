#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 > 0)
      return false;
    target = sum / 2;
    memo = vector<vector<int>>(nums.size(), vector<int>(sum, -1));
    return dfs(nums, 0, 0);
  }
private:
  int target;
  vector<vector<int>> memo;
  int dfs(vector<int> &nums, int i, int currsum) {
    // add i or not
    if (i == nums.size())
      return false;
    if (currsum == target) {
      return true;
    }
    if (memo[i][currsum] >= 0)
      return memo[i][currsum];
    return memo[i][currsum] =
               dfs(nums, i + 1, currsum + nums[i]) || dfs(nums, i + 1, currsum);
  }
};