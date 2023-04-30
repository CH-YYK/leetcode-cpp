class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.empty()) return {-1, -1};
    int lower = lower_bound(nums, target);
    int upper = upper_bound(nums, target) - 1;
    if(lower == nums.size() || nums[lower] != target || nums[upper] != target)
      return {-1, -1};
    return {lower, upper};
  }
private:
  int lower_bound(vector<int>& nums, int target) {
    // [l, r)
    int l = 0, r = nums.size(), m;
    while(l < r) {
      m = (l + r) / 2;
      // move r left event though the target was found
      if(nums[m] >= target)
        r = m;
      else
        l = m + 1;
    }
    return l; // l == r
  }
  int upper_bound(vector<int>& nums, int target) {
    int l = 0, r = nums.size(), m;
    while(l < r) {
      m = (l + r) / 2;
      // let r stop right before the target was found
      if(nums[m] > target)
        r = m;
      else
        l = m + 1;
    }
    return l;  // l == r
  }
};
