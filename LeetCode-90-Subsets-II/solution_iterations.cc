#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> res{{}};
    sort(begin(nums), end(nums));
    set<vector<int>> s;
    for(int i = 0; i < nums.size(); ++i) {
      int n = res.size();
      for(int j = 0; j < n; ++j) {
        vector<int> tmp = res[j];
        tmp.push_back(nums[i]);
        if(s.count(tmp)) continue;
        else {
          res.push_back(tmp);
          s.insert(tmp);
        }
      }
    }
    return res;
  }
};
