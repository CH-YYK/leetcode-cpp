#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    stack<int> nexts;
    int leftmost = nums.size(), rightmost = -1;
    for (int i = 0; i < nums.size(); ++i) {
      while (!nexts.empty() && nums[nexts.top()] > nums[i])
        nexts.pop();
      if (nexts.empty() && i > 0)  // handle edge case when i == 0
        leftmost = -1;
      else if (!nexts.empty() && nexts.top() < i - 1)
        leftmost = min(leftmost, nexts.top());
      nexts.push(i);
    }

    nexts = stack<int>();
    for (int i = nums.size() - 1; i >= 0; --i) {
      while (!nexts.empty() && nums[nexts.top()] < nums[i])
        nexts.pop();
      if (nexts.empty() && i < nums.size() - 1) // handle edge case when i == n-1
        rightmost = nums.size();
      else if (!nexts.empty() && nexts.top() > i + 1)
        rightmost = max(rightmost, nexts.top());
      nexts.push(i);
    }

    return leftmost >= rightmost ? 0 : rightmost - leftmost - 1;
  }
};
