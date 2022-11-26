#include <vector>
#include <iostream>
using namespace std;

/* K is guaranteed smaller than the sizes of nums1 and nums2
 *
 */
int findKthSmallest(vector<int>& nums1, vector<int>& nums2, int k) {
  int n1, n2;
  int l = 1, r = k;

  while(l < r) {
    n1 = (l + r) / 2;
    n2 = k+ 1 - n1;
    if(nums1[n1-1] == nums2[n2-1]) return nums1[n1-1];
    else if(n2 > 1 && nums1[n1-1] < nums2[n2-2]) r = n1-1;
    else if(n1 > 1 && nums1[n1-2] > nums2[n2-1]) l = n1+1;
    else return min(nums1[n1-1], nums2[n2-1]);
  }
  return min(nums1[l-1], nums2[k-l]);
}

int main() {
  vector<int> nums1 = {3,21,27,53,90};
  vector<int> nums2 = {4, 20, 21, 100};

  cout << findKthSmallest(nums1, nums2, 7);
  return 0;
}
