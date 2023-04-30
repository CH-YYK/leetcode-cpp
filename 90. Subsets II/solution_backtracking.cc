#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<int> subset;
    sort(begin(nums), end(nums));
    backtrack(nums, 0, subset);
    return res;
  }

private:
  vector<vector<int>> res;
  void backtrack(vector<int> &nums, int i, vector<int> subset) {
    if (i >= nums.size()) {
      res.push_back(subset);
      return;
    }

    for (int j = i; j <= nums.size(); ++j) {
      if (j > i && j < nums.size() && nums[j] == nums[j - 1])
        continue;
      if (j < nums.size())
        subset.push_back(nums[j]);
      backtrack(nums, j + 1, subset);
      if (j < nums.size())
        subset.pop_back();
    }
  };
};
