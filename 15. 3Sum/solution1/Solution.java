import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

class Solution {
  public List<List<Integer>> threeSum(int[] nums) {
    // return the triples (i, j, j) where nums[i] + nums[j] + nums[k] = 0
    // Normally it'd be O(n^3), but could be downgraded to O(n^2) when
    // integrated with 2Sum
    Set<List<Integer>> ans = new HashSet<>();
    for (int i = 0; i < nums.length; ++i) {
      List<List<Integer>> rest = twoSum(nums, -nums[i], i);
      for (List<Integer> r : rest) {
        List<Integer> tmp = Arrays.asList(nums[i], r.get(0), r.get(1));
        tmp.sort(null);
        ans.add(tmp);
      }
    }
    return new ArrayList<>(ans);
  }

  private List<List<Integer>> twoSum(int[] nums, int target, int start) {
    Map<Integer, Integer> resMap = new HashMap<>();
    List<List<Integer>> ans = new ArrayList<>();
    for (int l = start; l < nums.length; ++l) {
      if (resMap.containsKey(target - nums[l])) {
        ans.add(Arrays.asList(target - nums[l], nums[l]));
      } else {
        resMap.put(nums[l], l);
      }
    }
    return ans;
  }
}