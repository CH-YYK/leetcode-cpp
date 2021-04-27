#include <set>
#include <utility>
#include <vector>
#include <deque>
using namespace std;

/* Use sliding window [l, r] to maintain a monotonic queue that track the states for previous K indexes
 * * The state refer to the cumulative sums of subsequences
 * * the mq keep the states descending and put the maximum state at the leftmost.
 * * r walk through numbers and add newly computed state to the queue 
 * * l record the location to delete from mq
 */

class Solution {
public:
  int constrainedSubsetSum(vector<int> &nums, int k) {
    deque<pair<int, int>> mq; // <state, index>
    int res = nums[0];
    mq.push_back({res, 0});
    for (int r = 1; r < nums.size(); ++r) {
      int sum = max(nums[r] + mq.front().first, nums[r]);
      while (!mq.empty() && mq.back().first < sum)
        mq.pop_back();
      mq.push_back({sum, r});
      res = max(res, mq.front().first);
      if (mq.front().second == r - k) // make sure the mq will cover [r - k, r]
                                      // such that r - (r - k) == k
        mq.pop_front();
    }
    return res;
  }
};
