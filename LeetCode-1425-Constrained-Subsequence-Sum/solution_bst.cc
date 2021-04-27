#include <vector>
#include <set>
using namespace std;

/* Use sliding window [l, r] to maintain a BST of size k
 * * BST save the cumulative sums of subsequences in nums[r-k:r]
 * * r walk through numbers and add compute maximum cumulative sums and add to BST
 * * l record the location to delete from BST
 */

class Solution {
public:
  int constrainedSubsetSum(vector<int> &nums, int k) {
    multiset<int, greater<int>> s;
    vector<multiset<int>::iterator> loc(nums.size());
    int l = 0;
    loc[l] = s.insert(nums[l]);
    int res = nums[l];
    for (int r = 1; r < nums.size(); ++r) {
      loc[r] = s.insert(max(*s.begin() + nums[r], nums[r])); 
      if (r - l + 1 > k)
        s.erase(loc[l++]);
      res = max(res, *s.begin());
    }
    return max(res, *s.begin());
  }
};
