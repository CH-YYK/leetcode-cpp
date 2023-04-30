#include <vector>
#include <unordered_set>

using namespace std;

/* Backtracking:
 * * test every possibilities of 1-n in each backtracking step
 * * use a hashset to filter out the added number
 * * backtrack(nums, values) -> try adding num in nums to values during backtracking
 * O(2^N)
 */
class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<int> values;
    backtrack(nums, values);
    return res;
  }
private:
  unordered_set<int> s;
  vector<vector<int>> res;
  void backtrack(vector<int>& nums, vector<int>& values) {
    if(values.size() == nums.size()) {
      res.push_back(values);
      return;
    }
    for(int i : nums) {
      if(s.count(i)) continue;
      s.insert(i);
      values.push_back(i);
      backtrack(nums, values);
      s.erase(i);
      values.pop_back();
    }
  }
};
