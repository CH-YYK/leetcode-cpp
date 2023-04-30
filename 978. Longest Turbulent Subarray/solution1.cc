#include <vector>

using namespace std;

/* example triplet -> use (i-1, i, i+1)
 * nums[i-1] == nums[i] skip nums[i-1]
 * Fail(nums[i-1], nums[i], nums[i+1]) -> i - l + 1
 * i == n-1 -> i - l + 1
 */
class Solution {
public:
  int maxTurbulenceSize(vector<int> &arr) {
    int n = arr.size();
    if (n == 1)
      return 1;
    if (n == 2)
      return arr[0] == arr[1] ? 1 : 2;
    int res = 1;

    int l = 0, diff, prev = 1;
    for(int i = 1; i < n; ++i) {
      diff = cmp(arr[i-1], arr[i]);
      if(diff == 0) l = i;
      else if(i == n-1 || diff * cmp(arr[i], arr[i+1]) >= 0) {
        res = max(res, i - l + 1);
        l = i;
      }
    }
    return res;
  }
private:
  int cmp(int& lhs, int& rhs) {
    if(lhs == rhs) return 0;
    else return lhs > rhs ? 1 : -1;
  }
};
