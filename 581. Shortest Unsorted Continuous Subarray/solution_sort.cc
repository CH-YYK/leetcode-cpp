#include <vector>
using namespace std;

class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    // 2,6,4,8,10,9,15
    // 0,1,2,3,4,  5,  6
    // (2,0), (4,2), (6,1), (8,3), (9,5), (10,4), (15,6)
    // find the first unmatched index and last unmatched index.
    vector<pair<int, int>> buffer;
    for (int i = 0; i < nums.size(); ++i)
      buffer.emplace_back(nums[i], i);
    sort(buffer.begin(), buffer.end());
    int l = 0, r = nums.size() - 1;
    while (l <= r && buffer[l].second == l)
      ++l;
    while (r >= l && buffer[r].second == r)
      --r;
    return r - l + 1;
  }
};
