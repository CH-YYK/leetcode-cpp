#include <iostream>
#include <vector>
using namespace std;

/* K is guaranteed smaller than the sizes of nums1 and nums2
 *
 */
int findKthSmallest(vector<int> &nums1, vector<int> &nums2, int k) {
  int n1 = nums1.size(), n2 = nums2.size();

  if(n1 + n2 < k) return -1;

  int l = 0, r = min(k-1, n1-1);

  int i = 0, j = 0; // find i,j st nums1[i] > nums2[j-1] && nums2[j] > nums1[i-1]

  while(l <= r) {
    i = (l + r) / 2;
    j = k-1-i;
    if(nums2[j-1] > nums1[i]) // i is too small
      l = i + 1;
    else if(i > 0 && nums1[i-1] > nums2[j]) // i is too large
      r = i - 1;
    else // i is perfect
      return min(nums1[i], nums2[j]);
  }
  return -1;
}

int main() {
  vector<int> nums1 = {3, 21, 27, 53, 90};
  vector<int> nums2 = {91, 92};

  cout << findKthSmallest(nums1, nums2, 3);
  return 0;
}
