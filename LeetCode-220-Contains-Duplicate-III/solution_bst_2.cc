#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
    const int n = nums.size();
    if (k == 0)
      return false;
    multiset<int> s;
    multiset<int>::iterator it;

    for (int l = 0; l < n; ++l) {
      if (s.size() >= 1) {
        it = s.upper_bound(nums[l]);  // *it > nums[l], lower_bound >= nums[l], prev(it) <= nums[l]
        if (it != s.begin() && diff(*prev(it), nums[l]) <= t)
          return true;
        if (it != s.end() && diff(*it, nums[l]) <= t)
          return true;
        if (l >= k)
          s.erase(s.lower_bound(nums[l - k]));
      }
      s.insert(nums[l]);
    }
    return false;
  }

private:
  long diff(const long &lhs, const long &rhs) {
    if (lhs > rhs)
      return lhs - rhs;
    else
      return rhs - lhs;
  }
};
