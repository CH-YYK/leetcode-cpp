/* Stack
 *
 */

class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> s;
    int n = nums.size();

    vector<int> res(n, -1);

    // start from i = 2n-1, get index by j = i%n;
    for(int i = 2*n - 1; i >= 0; --i) {
      int j = i % n;
      while(!s.empty()) {
        if(nums[j] < nums[s.top()]) {
          res[j] = nums[s.top()];
          break;
        }
        else
          s.pop();
      }
      s.push(j);
    }
    return res;
  }
};
