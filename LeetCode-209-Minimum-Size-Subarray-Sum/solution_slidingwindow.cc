#include <vector>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int len = 1e9, sum = 0, l = 0;
    int n = nums.size();
    for(int r = 0; r < nums.size(); ++r) {
      sum += nums[r];
      while(sum >= target) {
        len = min(len, r - l + 1);
        sum -= nums[l++];
      }
    }
    return len;
  }
};
