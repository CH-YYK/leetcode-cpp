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
    int l = 0;
    for (int r = 0; r < n; ++r) {
      if (s.size() == k + 1) {
        s.erase(s.lower_bound(nums[l]));
        auto it = s.upper_bound(nums[l]);
        auto itp = prev(it);
        if ((it != s.begin() && diff(nums[l], *itp) <= t) ||
            (it != s.end() && diff(nums[l], *it) <= t))
          return true;
        l++;
      }
      s.insert(nums[r]);
    }
    for (; l < n - 1; ++l) {
      s.erase(s.lower_bound(nums[l]));
      auto it = s.upper_bound(nums[l]);
      auto itp = prev(it);
      if ((it != s.begin() && diff(nums[l], *itp) <= t) ||
          (it != s.end() && diff(nums[l], *it) <= t))
        return true;
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
