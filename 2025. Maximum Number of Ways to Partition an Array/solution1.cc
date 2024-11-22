#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int waysToPartition(vector<int> &nums, int k) {
    // gap[i] = sum(nums[i:]) - sum(nums[:i])
    // prefix[i] = sum(nums[:i])
    // suffix[i] = sum(nums[i:])
    vector<long> gap(nums.size(), 0), prefix(nums.size(), 0), suffix(nums.size(), 0);
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (i == 0)
        suffix[n - 1 - i] = nums[n - 1 - i];
      else {
        prefix[i] = prefix[i - 1] + nums[i - 1];
        suffix[n - 1 - i] = suffix[n - i] + nums[n - 1 - i];
      }
    }
    // Be careful with the value overflow, because it'd locate to arbitray keys.
    unordered_map<long, int> right_gap_count, left_gap_count;
    // Existing difference between suffix and prefix for pivot in [1, n-1]
    for (int i = 1; i < n; ++i) {
      gap[i] = suffix[i] - prefix[i];
      right_gap_count[gap[i]]++;
    }
    long long max_ways = 0;
    if (right_gap_count.count(0))
      max_ways = right_gap_count[0];

    for (int i = 0; i < n; ++i) {
      // replace nums[i] by k and try pivot > i
      // left = left + k - nums[i] -> gap = gap + nums[i] - k
      // right = right + k - nums[i] -> gap = gap + k - nums[i]
      long long curr = 0;
      long long diff = k - nums[i];

      // move pivot=i from right to left.
      if (i > 0) {
        long long dd = gap[i];
        if (--right_gap_count[dd] == 0)
          right_gap_count.erase(dd);
        left_gap_count[dd]++;
      }

      // pivot in [1, i], right side increased by diff
      if (left_gap_count.count(-diff)) {
        curr += left_gap_count[-diff];
      }

      // pivot in [i + 1, n-1]
      if (right_gap_count.count(diff)) {
        curr += right_gap_count[diff];
      }
      max_ways = max(max_ways, curr);
    }
    return max_ways;
  }
};