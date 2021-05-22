#include <vector>
#include <deque>
using namespace std;

/* Use monotonic queue to store S_l's in ascending order in dq
 *  * Given S_h, pop dq.front() if S_h - S_l >= target, as current S_h is the closest S_h to S_l
 *  * Push S_h as a new S_l to dq and pop out larger ones (in this problem S_h will always be larger as only positive numbers)
 */
class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int len = 1e9, sum = 0, l = 0;
    vector<int> presum(nums.size() + 1, 0);
    for(int i = 0; i < nums.size(); ++i)
      presum[i+1] = presum[i] + nums[i];
    deque<int> dq;

    for(int i = 0; i < presum.size(); ++i) {
      while(!dq.empty() && presum[i] - presum[dq.front()] >= target) {
        len = min(len, i - dq.front());
        dq.pop_front();
      }
      while(!dq.empty() && presum[i] <= presum[dq.back()])
        dq.pop_back();
      dq.push_back(i);
    }
    return len == 1e9 ? 0 : len;
  }
};
