#include <vector>

using namespace std;

/* Monotonic Queue/deque, keep the values in queue ascending
 */
class Solution {
public:
  vector<int> mostCompetitive(vector<int> &nums, int k) {
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
      while (!res.empty() && nums[i] < res.back() && n - i > k) {
        k++;
        res.pop_back();
      }
      if (k > 0) {
        res.push_back(nums[i]);
        k--;
      }
    }
    return res;
  }
};
