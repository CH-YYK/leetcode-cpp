#include <vector>
#include <deque>

using namespace std;

/* Monotonic Queue/deque, keep the values in queue ascending
 */
class Solution {
public:
  vector<int> mostCompetitive(vector<int> &nums, int k) {
    deque<int> dq;
    int n = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
      while (!dq.empty() && nums[i] < nums[dq.back()] && n - i > k) {
        k++;
        dq.pop_back();
      }
      if (k > 0) {
        dq.push_back(i);
        k--;
      }
    }
    vector<int> res;
    while (!dq.empty())
      res.push_back(nums[dq.front()]), dq.pop_front();
    return res;
  }
};
