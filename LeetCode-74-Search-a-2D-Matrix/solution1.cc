#include <vector>
using namespace std;

/* * Binary search the heading of row.
 * * Binary search the value in the row.
 */
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int l = 0, r = m - 1, mid;
    while (l <= r) {
      mid = (l + r) / 2;
      if (matrix[mid][0] == target)
        return true;
      else if (matrix[mid][0] > target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    if (r < 0)
      return false;
    vector<int> &nums = matrix[r];
    l = 0, r = n - 1;
    while (l <= r) {
      mid = (l + r) / 2;
      if (nums[mid] == target)
        return true;
      else if (nums[mid] > target)
        r = mid - 1;
      else
        l = mid + 1;
    }
    return false;
  }
};
