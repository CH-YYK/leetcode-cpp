#include <stack>
#include <vector>

using namespace std;

/* Find maximum score of a good subarray
 * score(i,j) = min(nums[i:j]) * (j-i+1), get the maximum score(i,j)
 *
 * According to the formula, we can see that score is kind of determined by the min(nums[i:j])
 * 1> firstly find the subarray [i:j] where a nums[k] stay minimum for each k in [i:j]
 * 2> compute the score for each nums[k]
 * 3> output the maximum score (k is used to filter the result, i<=k<=j)
 *
 * using descending monotune stack (ascending stack) to find left smaller and right smaller
 */
class Solution {
public:
  int maximumScore(vector<int> &nums, int k) {
    int n = nums.size();
    stack<int> stk;
    vector<int> left(n, -1);
    vector<int> right(n, n);

    // next smaller on left
    for(int i = 0; i < nums.size(); ++i) {
      while(!stk.empty() && nums[stk.top()] >= nums[i])
        stk.pop();
      if(!stk.empty()) left[i] = stk.top();
      stk.push(i);
    }

    stk = stack<int>();
    // next smaller on right
    for(int i = n-1; i >= 0; --i) {
      while(!stk.empty() && nums[stk.top()] >= nums[i])
        stk.pop();
      if(!stk.empty()) right[i] = stk.top();
      stk.push(i);
    }

    int res = 0;
    // get optimal results for each num restricted by k
    for(int i = 0; i < n; ++i) {
      int l = left[i] + 1, r = right[i] - 1;
      if(l > k || r < k) continue;
      res = max(res, nums[i] * (r-l+1));
    }
    return res;
  }
};
