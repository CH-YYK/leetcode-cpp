#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int validSubarrays(vector<int> &nums) {
    // A subarray is valid if its leftmost element is a minimal
    // For an `i` in nums, find the longest subarray starting from i
    // with all elements >= nums[i].
    // This brute force solution will take O(N^2).
    //
    // We are actually finding the next smaller element
    //   -> monotonic stack
    stack<int> stk;
    int n = nums.size();
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      // finding the next smaller to right
      // pop the elements if >= nums[i], then stk.top() is the next smaller to
      // right
      while (!stk.empty() && nums[i] <= nums[stk.top()])
        stk.pop();

      if (stk.empty()) {
        ans += n - i;
      } else
        ans += stk.top() - i;
      stk.push(i);
    }
    return ans;
  }
};