#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    // BST: values are sorted in the sliding window
    multiset<int> s;
    vector<int> res;
    int l = 0;
    for (int r = 0; r < nums.size(); ++r) {
      s.insert(nums[r]);
      if (r - l + 1 >= k) {
        res.push_back(s.rbegin()->first);
        s.erase(s.equal_range(nums[l]).first);
        l++;
      }
    }
    return res;
  }
};
