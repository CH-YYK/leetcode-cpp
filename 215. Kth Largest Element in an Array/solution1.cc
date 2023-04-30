#include <vector>

using namespace std;

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    int l = 0, r = nums.size(), target = nums.size() - k;
    while(l < r) {
      int m = pivot2(nums, l, r);
      if(m == target) return nums[m];
      if(m < target) l = m + 1;
      else r = m;
    }
    return nums[l];
  }
private:
  int pivot(vector<int>& nums, int l, int r) {
    // use the first element as pivot value and rearrange the array
    int first = l + 1, last = r - 1, key = nums[l];
    while(true) {
      while(first < r && nums[first] <= key) ++first;
      while(last > l && nums[last] >= key) --last;
      if(first >= last) break;
      swap(nums[first], nums[last]);
    }
    swap(nums[l], nums[last]);
    return last;
  }

  int pivot2(vector<int>& nums, int l, int r) {
    int first = l, last = r - 1, key = nums[l];
    while(first < last) {
      // nums[last] < key -> nums[first]
      while(first < last && nums[last] >= key) --last;
      nums[first] = nums[last];

      // nums[first] > key -> nums[last]
      while(first < last && nums[first] <= key) ++first;
      nums[last] = nums[first];
    }
    // put pivot key to the correct index, nums[first] > key
    nums[first] = key;
    return first;
  }
};
