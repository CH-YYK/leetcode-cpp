
class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    // array and sub-arrays' lengths must be odd
    int l = 0, r = nums.size() - 1, a;
    while(l < r) {
      a = (l + r) / 2;
      if(nums[a] == nums[a+1])
        if((r - a + 1) % 2 == 0) r = a-1;
        else l = a;
      else {
        if((a - l + 1) % 2 == 0) l = a + 1;
        else r = a;
      }
    }
    return nums[l];
  }
};
