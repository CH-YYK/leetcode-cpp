#include <vector>
using namespace std;

/* Sliding window get k-num sum for each index
 * Search for best combination for the window of sums
 * memoization could be applied to boost search
 */
class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
    int n = nums.size();
    // sliding window
    vector<int> sums(n - k + 1, 0); // n-(k-1)
    int l = 0, sum = 0;
    for (int r = 0; r < n; ++r) {
      sum += nums[r];
      if (r - l + 1 == k) {
        sums[l] = sum;
        sum -= nums[l++];
      }
    }
    vector<int> path;
    dfs(sums, 0, path, 0, k);
    return res;
  }

private:
  int maxsum = 0;
  vector<int> res;

  void dfs(vector<int> &sums, int i, vector<int> path, int cusum, int k) {
    if (i == sums.size() || path.size() == 3) {
      if (cusum > maxsum) {
        maxsum = cusum;
        res = path;
      }
      return;
    }
    for (int j = i; j < sums.size(); ++j) {
      if (path.size() <= 3) {
        path.push_back(j);
        dfs(sums, j + k, path, cusum + sums[j], k);
        path.pop_back();
      }
    }
    return;
  }
};
