#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    // BST: values are sorted in the sliding window
    map<int, int, greater<int>> s;
    vector<int> res;
    int l = 0;
    for (int r = 0; r < nums.size(); ++r) {
      if (r - l + 1 < k)
        s[nums[r]]++;
      else {
        s[nums[r]]++;
        res.push_back(s.begin()->first);
        if (--s[nums[l]] == 0)
          s.erase(nums[l]);
        l++;
      }
    }
    return res;
  }
};
