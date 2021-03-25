#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
  bool find132pattern(vector<int> &nums) {
    int n = nums.size();
    int leftmin = 0, rightnextmin = n - 1;

    // initialization;
    vector<int> rightmins(n, n);
    vector<int> leftmins(n, -1); // record right max smaller than nums[k]
    stack<int> s;

    // one pass find min leftmins
    for (int i = 1; i < n; ++i) {
      if (nums[i] < nums[leftmin])
        leftmin = i;
      else if (nums[i] > nums[leftmin])
        leftmins[i] = leftmin;
    }
    // find next greater at left, update corresponding right smaller for s.top()
    for (int i = 0; i < n; ++i) {
      while(!s.empty() && nums[s.top()] <= nums[i]) {
        s.pop();
      }
      if(!s.empty()) {
        if(rightmins[s.top()] == n) rightmins[s.top()] = i;
        else if(nums[i] > nums[rightmins[s.top()]])
          rightmins[s.top()] = i;
      }
      s.push(i);
    }
    // check for every i and return true if nums[rightmins[i]] > nums[leftmins[i]]
    for (int i = 0; i < n; ++i) {
      if (leftmins[i] == -1 || rightmins[i] == n)
        continue;
      if (nums[rightmins[i]] > nums[leftmins[i]])
        return true;
    }
    return false;
  }
};
