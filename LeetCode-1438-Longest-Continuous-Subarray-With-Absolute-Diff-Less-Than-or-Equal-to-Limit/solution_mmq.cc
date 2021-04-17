#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &nums, int limit) {
    deque<int> qmin, qmax;
    const int n = nums.size();
    int l = 0, maxlen = 0;

    for(int r = 0; r < n; ++r) {
      while(!qmin.empty() && nums[qmin.back()] >= nums[r])
        qmin.pop_back();
      while(!qmax.empty() && nums[qmax.back()] <= nums[r])
        qmax.pop_back();
      if(qmin.empty()) // nums[r] is the minimum so far;
        while(!qmax.empty() && nums[qmax.front()] - nums[r] > limit)
          l = qmax.front() + 1, qmax.pop_front();
      if(qmax.empty()) // nums[r] is the maximum so far;
        while(!qmin.empty() && nums[r] - nums[qmin.front()] > limit)
          l = qmin.front() + 1, qmin.pop_front();
      qmax.push_back(r);
      qmin.push_back(r);
      maxlen = max(maxlen, r - l + 1);
    }
    return maxlen;
  }
};
