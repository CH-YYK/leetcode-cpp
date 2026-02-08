import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
  public List<List<Integer>> threeSum(int[] nums) {
    List<List<Integer>> ans = new ArrayList<>();

    for (int i = 0; i < nums.length; ++i) {
      // Skip duplicates
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      // Since nums is sorted, then use Two pointers to find where (j, k)
      // nums[j] + nums[k] == -nums[i]
      int j = i + 1, k = nums.length - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == 0) {
          ans.add(Arrays.asList(nums[i], nums[j], nums[k]));
          j++;
          k--;
          // Skip duplicates
          while (j < k && nums[j] == nums[j - 1])
            j++;
        } else if (sum < 0)
          j++;
        else
          k--;
      }
    }
    return ans;
  }
}