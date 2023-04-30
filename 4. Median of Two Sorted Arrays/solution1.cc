#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<int> medians;

    int l = 0, r = m, mid;
    int left, right;
    while(l < r) {
      mid = (l + r)/ 2;
      auto dir = check(nums2, nums1[mid], mid, m - 1 - mid);
      if (dir == 0)
        return nums1[mid];
      else if (dir < 0) {
        l = mid + 1;
        if (dir == -1)
          medians.push_back(nums1[mid]);
      } else if (dir > 0) {
        r = mid;
        if (dir == 1)
          medians.push_back(nums1[mid]);
      }
    }

    l = 0, r = n;
    while(l < r) {
      mid = (l + r) / 2;
      auto dir = check(nums1, nums2[mid], mid, n - 1- mid);
      if(dir == 0) return nums2[mid];
      else if(dir < 0) {
        l = mid + 1;
        if(dir == -1) medians.push_back(nums2[mid]);
      } else if(dir > 0) {
        r = mid;
        if(dir == 1) medians.push_back(nums2[mid]);
      }
    }

    return (medians.front() + medians.back()) / 2;
  }
private:
  int check(vector<int>& nums, int mid, int left, int right) {
    if(mid <= *nums.begin()) right += nums.size();
    else if(mid > nums.back()) left += nums.size();
    else {
      auto it = prev(lower_bound(nums.begin(), nums.end(), mid));
      left += it - nums.begin() + 1;
      right += nums.end() - 1 - it;
    }
    return left - right;
  }
};
