#include <vector>

using namespace std;

class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    int l = 0;
    double sum = 0;
    double res = INT_MIN;
    for (int r = l; r < nums.size(); ++r) {
      sum += nums[r];
      if (r - l + 1 > k) {
        sum -= nums[l++];
      }
      if (r - l + 1 == k) {
        res = max(res, sum / k);
      }
    }
    return res;
  }
};