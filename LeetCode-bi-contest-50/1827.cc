#include <vector>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums) {
    int res = 0;
    for(int i = 1; i < nums.size(); ++i) {
      res += max(nums[i-1] + 1 - nums[i], 0);
      nums[i] = max(nums[i], nums[i-1] + 1);
    }
    return res;
  }
};
