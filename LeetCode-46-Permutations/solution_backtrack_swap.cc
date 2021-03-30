#include <unordered_set>
#include <vector>

using namespace std;

/* Backtracking:
 * * test every possibilities in nums at each backtracking step
 * * by swapping current position i with any position j > i
 * * then backtracking from i+1
 * backtrack(nums, i) -> start backtrack nums from i
 */

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    backtrack(nums, 0);
    return res;
  }

private:
  vector<vector<int>> res;
  void backtrack(vector<int> &nums, int i) {
    if (i == nums.size() - 1) {
      res.push_back(nums);
      return;
    }
    for (int j = i; j < nums.size(); ++j) {
      // i==j means donot swap at i so that some possibilities can be kept
      swap(nums[i], nums[j]);
      backtrack(nums, i + 1);
      swap(nums[j], nums[i]);
    }
  }
};
