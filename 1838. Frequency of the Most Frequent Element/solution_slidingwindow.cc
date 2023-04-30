#include <vector>
using namespace std;

class Solution {
public:
  int maxFrequency(vector<int> &nums, int k) {
    long sum = 0;
    int l = 0, n = nums.size();
    int res = 0;
    sort(nums.begin(), nums.end());
    for (int r = 0; r < n; ++r) {
      sum += nums[r];
      while (sum + k < (long)(r - l + 1) * nums[r])
        sum -= nums[l++];
      res = max(res, r - l + 1);
    }
    return res;
  }
};
