#include <unordered_map>
#include <set>
#include <vector>
using namespace std;
// relevant to 1438
class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
    const int n = nums.size();
    if (k == 0)
      return false;
    unordered_map<long, long> m;
    for (int l = 0; l < n; ++l) {
      long id = getId(nums[l], t);
      if (m.count(id))
        return true;
      if (m.count(id - 1) && diff(nums[l], m[id - 1]) <= t)
        return true;
      if (m.count(id + 1) && diff(nums[l], m[id + 1]) <= t)
        return true;

      // each bucket only contain 1 element if get here
      m[id] = nums[l];
      if (l >= k)
        m.erase(getId(nums[l - k], t));
    }
    return false;
  }

private:
  long getId(long num, long t) {
    if (t == 0)
      t += 1;
    return num >= 0 ? num / t : (num + 1) / t - 1;
  }
  long diff(const long &lhs, const long &rhs) {
    if (lhs > rhs)
      return lhs - rhs;
    else
      return rhs - lhs;
  }
};
