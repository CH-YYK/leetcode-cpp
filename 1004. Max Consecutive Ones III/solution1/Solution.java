class Solution {
  public int longestOnes(int[] nums, int k) {
    int l = 0;
    int maxOnes = 0;
    // Longest subarray containing at most k' zeros.
    for (int r = 0; r < nums.length; ++r) {
      if (nums[r] == 0) {
        while (k == 0 && nums[l] == 1) {
          l++;
        }
        if (k > 0)
          k--;
        else if (nums[l] == 0)
          l++;
      }
      maxOnes = Math.max(maxOnes, r - l + 1);
    }
    return maxOnes;
  }
}