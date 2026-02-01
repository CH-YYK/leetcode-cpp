import java.util.List;

class Solution {
  public int[] sortedSquares(int[] nums) {
    int n = nums.length;
    int[] res = new int[n];
    // Find the z, `nums[z] == 0`
    int z = 0;
    while (z < n && nums[z] < 0)
      z++;
    int l = z - 1, r = z;
    int i = 0;
    while (l >= 0 && r < n) {
      if (Math.abs(nums[l]) <= Math.abs(nums[r])) {
        res[i++] = nums[l] * nums[l];
        l--;
      } else {
        res[i++] = nums[r] * nums[r];
        r++;
      }
    }
    while (l >= 0) {
      res[i++] = nums[l] * nums[l];
      l--;
    }
    while (r < n) {
      res[i++] = nums[r] * nums[r];
      r++;
    }

    return res;
  }
}