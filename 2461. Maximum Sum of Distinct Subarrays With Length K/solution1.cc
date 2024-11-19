#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  long long maximumSubarraySum(vector<int> &nums, int k) {
    // maximum subarray sum  of all subarrays of nums that

    // The length of the subarray is k.
    // All the elements of the subarray are distinct.

    // Sliding window. [l, r]
    // To ensure the elements are distinct in the window, update l when nums[r]
    // == nums[l].
    // Use unordered_map to track the location of each element in the window,
    // and update l to map[nums[r]] + 1, and update the sum accordingly.

    int l = 0;
    long long maxSum = 0;
    long long sum = 0;
    unordered_map<int, int> loc;
    for (int r = 0; r < nums.size(); ++r) {
      if (r - l + 1 > k) {
        loc.erase(nums[l]);
        sum -= nums[l++];
      }
      if (loc.count(nums[r])) {
        while (l <= loc[nums[r]])
          sum -= nums[l++];
      }
      sum += nums[r];
      loc[nums[r]] = r;
      if (r - l + 1 == k)
        maxSum = max(maxSum, sum);
    }
    return maxSum;
  }
};