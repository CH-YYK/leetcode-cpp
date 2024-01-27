#include <algorithm>
#include <iostream>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  long long maxSum(vector<int> &nums, int m, int k) {
    // Standard sliding window problem. 
    int l = 0;
    long long ans = 0, sum = 0;

    unordered_map<int, int> mp;
    for (int r = 0; r < nums.size(); ++r) {
      mp[nums[r]]++;
      sum += nums[r];
      if (r - l + 1 == k) {
        if (mp.size() >= m)
          ans = max(ans, sum);
        if (mp[nums[l]]-- == 1) {
          mp.erase(nums[l]);
        }
        sum -= nums[l];
        l++;
      }
    }
    return ans;
  }
};