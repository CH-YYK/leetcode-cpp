class Solution {
  public int searchInsert(int[] nums, int target) {
    // find target from a sorted array nums
    // or find `m` where nums[m] > target.
    int l = 0, r = nums.length;
    while (l < r) {
      int m = (l + r) / 2;
      if (nums[m] == target)
        return m;
      else if (nums[m] < target)
        l = m + 1;
      else
        r = m;
    }
    return l;
  }
}