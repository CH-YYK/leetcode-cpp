/*
 * We use the upper bound of search scope as the reference for the comparison with the pivot element,
 * while in the classical binary search the reference would be the desired value.
 * When the result of comparison is equal (i.e. Case #3), we further move the upper bound,
 * while in the classical binary search normally we would return the value immediately.
 */

/*
  pivot point position, p, can take value from [0, nums.size()-1]
  * if we have non-decreasing [m, r], p must take value from [l, m]
  * while if we have non-decreasing [l, m], p can either take l or from [m + 1, r]
  * So every time we are going to pick [m+1, r] given current non-decreasing [l, m], 
  *    take l into account as well.
  *
  * To handle duplicates
  * When nums[m] == nums[l], it's always hard to guarantee that [l, m] is non-decreasing
  *   - we firstly check whether nums[l] would be the minimum
  *   - then advance l by 1 step to skip nums[l] as nums[l] would not be the only minimum if [l,m] is non-decreasing
 */

class Solution {
public:
  int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while(low < high) {
      int pivot = (low + high) / 2;
      if(nums[pivot] < nums[high])
        high = pivot;
      else if(nums[pivot] > nums[high])
        low = pivot + 1;
      else
        high--;
    }
    return nums[low];
  }
};


class Solution2 {
public:
  int findMin(vector<int>& nums){
    int l = 0, r = nums.size() - 1, m;
    while(l < r) {
      m = (l + r) / 2;
      if (nums[m] == nums[r]) {
        r--;
        // if(nums[m] == nums[l])
        //  l++;
      }
      else if(nums[m] < nums[r]) // increasing in [m, r], min in [l, m]
        r = m;
      else  // increasing in [l, m], min in [m+1, r]
        l = m + 1;
    }
    return nums[l];
  }
};


class Solution3 {
public:
  int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, m, min_ = nums[0];
    while(l < r) {
      m = (l + r) / 2;
      if(nums[m] == nums[l]) {
        min_ = min(nums[l], min_);
        l++;
      } else if(nums[m] > nums[l]) {
        min_ = min(nums[l], min_);
        l = m + 1;
      } else
        r = m;
    }
    return min(nums[l], min_);
  }
};
