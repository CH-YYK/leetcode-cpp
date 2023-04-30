class Solution {
public:
  bool search(vector<int>& nums, int target) {
    // binary search on [l, r)
    int l = 0, r = nums.size(), m;
    while(l < r) {
      m = (l + r) / 2;
      if(nums[m] == target) return true;
      if(nums[m] == nums[l]) ++l;
      else if(nums[m] > nums[l]) {  // increasing in [l,m]
        if(target < nums[l] || target > nums[m])  // in [l, m] ?
          l = m + 1;
        else
          r = m;
      } else {
        if(target > nums[r-1] || target < nums[m])  // in [m, r)
          r = m;
        else
          l = m + 1;
      }
    }
    return false;
  }
};
