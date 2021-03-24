#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  bool find132pattern(vector<int> &nums) {
    int n = nums.size();
    int leftmin = 0, rightnextmin = n - 1;

    // initialization
    map<int, int, greater<int>> map_;
    vector<int> rightmins(n, n);
    vector<int> leftmins(n, -1);
    map_[nums[n - 1]] = n - 1;

    for (int i = 1; i < n; ++i) { // one pass find min leftmins
      if (nums[i] < nums[leftmin])
        leftmin = i;
      else if (nums[i] > nums[leftmin])
        leftmins[i] = leftmin;
    }

    for (int i = n - 2; i >= 0; --i) {     // BST find max rightmins
      auto it = map_.upper_bound(nums[i]); // *it < nums[i]
      if (it != map_.end())
        rightmins[i] = it->second;
      map_[nums[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
      if (leftmins[i] == -1 || rightmins[i] == n)
        continue;
      if (nums[rightmins[i]] > nums[leftmins[i]])
        return true;
    }
    return false;
  }
};
