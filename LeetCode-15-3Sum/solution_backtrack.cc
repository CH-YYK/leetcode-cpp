#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<int> values;
    find2Sum(nums, 0, values, 0);
    return res;
  }

private:
  vector<vector<int>> res;
  unordered_set<int> s;
  void find2Sum(vector<int> &nums, int i, vector<int> &values, int target) {
    if (values.size() > 3)
      return;

    if (values.size() == 3 && target == 0) {
      res.push_back(values);
      return;
    }
    for (int j = i; j < nums.size(); ++j) {
      if (j > i && nums[j] == nums[j - 1])
        continue;
      values.push_back(nums[j]);
      find2Sum(nums, j + 1, values, target - nums[j]);
      values.pop_back();
    }
  }
};
