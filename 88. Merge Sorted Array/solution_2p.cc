#include <vector>
using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    // start from end to avoid making extra copy
    int p1 = m - 1, p2 = n - 1;
    for (int i = m + n - 1; i >= 0; --i) {
      if (p1 >= 0 && p2 >= 0) {
        if (nums1[p1] > nums2[p2])
          swap(nums1[p1--], nums1[i]);
        else
          swap(nums2[p2--], nums1[i]);
      } else if (p2 >= 0)
        swap(nums1[i], nums2[p2--]);
      else
        return;
    }
  }
};
