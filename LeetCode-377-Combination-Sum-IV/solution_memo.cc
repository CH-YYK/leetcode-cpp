#include <vector>
using namespace std;

class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    memo = vector<int>(target + 1, -1);
    return numcomb(nums, target);
  }

private:
  vector<int> memo;
  int numcomb(vector<int> &nums, int target) {
    if (target < 0)
      return 0;
    if (target == 0)
      return 1;

    if (memo[target] >= 0)
      return memo[target];
    int res = 0;
    for (int j = 0; j < nums.size(); ++j) {
      res += numcomb(nums, target - nums[j]);
    }
    return memo[target] = res;
  }
};
