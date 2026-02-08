class Solution {
  public int maxArea(int[] height) {
    // A pillar at i can determine the area with pillar at j if height_j <=
    // height_i.
    int l = 0, r = height.length - 1;
    int res = 0;
    while (l < r) {
      int area = Math.min(height[l], height[r]) * (r - l);
      res = Math.max(res, area);
      if (height[l] < height[r])
        l++;
      else
        r--;
    }
    return res;
  }
}