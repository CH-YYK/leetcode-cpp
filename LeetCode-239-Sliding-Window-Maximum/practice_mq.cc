#include <vector>
#include <deque>

using namespace std;

/* We are interested in the current maximum and next maximum when the subarray popped the current maximum
 * Use a queue in which data are sorted descending so that value at top are always maximum
 * Adding new value will pop all values that are less
 */
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> dq;
    vector<int> res;
    for(int r = 0; r < nums.size(); ++r) {
      while(!dq.empty() && nums[dq.back()] < nums[r])
        dq.pop_back();
      dq.push_back(r); // add nums[r]
      if (r - k + 1 >= 0) { // r - l + 1 = k -> l = r - k + 1
        if (r - k == dq.front())  // pop nums[l]
          dq.pop_front();
        res.push_back(nums[dq.front()]);
      }
    }
    return res;
  }
};
