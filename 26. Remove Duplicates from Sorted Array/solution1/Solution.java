class Solution {
  public int removeDuplicates(int[] nums) {
    int l = 1;
    for (int r = 1; r < nums.length; r++) {
      if (nums[r] == nums[l - 1]) {
        continue;
      } else {
        swap(nums, l, r);
        l++;
      }
    }
    return l;
  }
  private void swap(int[] nums, int l, int r) {
    int tmp = nums[l];
    nums[l] = nums[r];
    nums[r] = tmp;
  }
}