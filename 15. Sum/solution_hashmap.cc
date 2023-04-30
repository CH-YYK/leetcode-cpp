#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, int> c;
    vector<vector<int>> res;
    sort(begin(nums), end(nums));
    for (int num : nums)
      c[num]++;
    for (int i = 0; i < n; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) // remove duplicates
        continue;
      for (int j = i + 1; j < n; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1])  // remove duplicates
          continue;
        int t = 0 - nums[i] - nums[j];

        if (t < nums[j])
          continue;
        if (!c.count(t))
          continue;
        if (c[t] >= 1 + (nums[i] == t) + (nums[j] == t))  // avoid overusing a number
          res.push_back({nums[i], nums[j], t});
      }
    }
    return res;
  }
};
