#include <vector>

using namespace std;

class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    if(nums.emtpy()) return true;

    int prev = nums[0];
    int res = 0;
    for(int i = 1; i < nums.size(); ++i) {
      if(prev > nums[i])
        nums[i] = prev, ++res;
      if(res > 1) return false;
      prev = nums[i];
    }
    return true;
  }
};
