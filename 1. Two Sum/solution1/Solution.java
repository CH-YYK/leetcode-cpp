import java.util.HashMap;

class Solution {
  public int[] twoSum(int[] nums, int target) {
    // Finding the indices i,j such that nums[i] + nums[j] = target;
    HashMap<Integer, Integer> resMap = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
      int num = nums[i];
      if (resMap.containsKey(target - num)) {
        return new int[] {resMap.get(target - num), i};
      }
      resMap.put(num, i);
    }
    return new int[] {0, 0};
  }
}