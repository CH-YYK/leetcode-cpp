#include <vector>
using namespace std;

class Solution {
public:
  int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
    long sumdiff = 0;
    int maxdiff = 0;
    int target = 0;
    for (int i = 0; i < nums1.size(); ++i) {
      int diff = abs(nums1[i] - nums2[i]);
      if (abs(diff) >= maxdiff)
        maxdiff = diff, target = nums2[i];
      sumdiff += diff;
    }
    int mindiff = 100000000;
    for (int i = 0; i < nums1.size(); ++i) {
      int diff = abs(target - nums1[i]);
      if (diff <= mindiff)
        mindiff = diff;
    }
    return (sumdiff - maxdiff + mindiff) % 1000000007;
  }

private:
  int abs(int diff) { return diff > 0 ? diff : -diff; }
};
