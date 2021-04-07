#include <iostream>
#include <vector>
using namespace std;

/* K is guaranteed smaller than the sizes of nums1 and nums2
 * Suppose we are going to pick K+1 elements (at least 1 element will be considered for two arrays)
 * and we guaranteed that nums1[i], nums2[j] must be Kth / K+1 th smallest number
 *
 * i takes values from [0, min(k-1, n1-1)] and i + j = k+1-2 -> j = k-1-i;
 * j takes values from [0, min(k-1, n2-1)]

 * stop criteria: nums1[i] > nums2[j-1] && nums2[j] > nums1[i-1]
 *
 * note: to simplify the edge cases
 *  *-> we assume that nums1 has shorter or equal length than nums2
 *  *-> such that j will never exceed the range of nums2
 */

int findKthSmallest(vector<int> &nums1, vector<int> &nums2, int k) {
  int n1 = nums1.size(), n2 = nums2.size();

  if (n1 + n2 < k)
    return -1;
  if (n1 + n2 == k)
    return max(nums1.back(), nums2.back());

  int l = 0, r = min(k - 1, n1 - 1);

  int i = 0, j = 0; // find i,j st nums1[i] > nums2[j-1] && nums2[j] > nums1[i-1]

  while (l < r) {
    i = (l + r) / 2;
    j = k - 1 - i;
    if (nums1[i] < nums2[j-1]) // i is too small
      l = i + 1;
    else if (i > 0 && nums1[i - 1] > nums2[j]) // i is too large
      r = i - 1;
    else // i is perfect
      return min(nums1[i], nums2[j]);
  }
  return min(nums1[l], nums2[k-1-l]);
}


int main() {
  vector<int> nums1 = {3, 21, 27, 53, 90};
  vector<int> nums2 = {91, 92};

  cout << findKthSmallest(nums1, nums2, 6);
  return 0;
}
