#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

/* Monotonic Queue: values are kept descending in the queue, so that the leftmost remain maximum.
 *  * pop_back from queue if queue.back() < num
 *  * pop_front from queue after the scanning window pop out the index
 *  * use deque as it allow O(1) push/pop for both sides. (and allow random access)
 */
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> q;
    vector<int> res;
    int l = 0;
    for (int r = 0; r < nums.size(); ++r) {
      while (!q.empty() && nums[q.back()] <= nums[r])
        q.pop_back();
      q.push_back(r);
      if (r - l + 1 >= k) {
        res.push_back(nums[q.front()]);
        if (l == q.front())
          q.pop_front();
        l++;
      }
    }
    return res;
  }
};
