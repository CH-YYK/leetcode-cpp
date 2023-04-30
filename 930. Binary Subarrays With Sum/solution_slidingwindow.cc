#include <vector>
using namespace std;

class Solution {
public:
  int numSubarraysWithSum(vector<int> &A, int S) {
    return atMost(A, S) - atMost(A, S - 1);
  }

private:
  /* Number of subarrays whose sums are at most S
   */
  int atMost(vector<int> &A, int S) {
    int l = 0, res = 0;
    if (S < 0)
      return 0;
    for (int r = 0; r < A.size(); ++r) {
      S -= A[r];
      while (S < 0)
          S += A[l++];
      res += r - l + 1; // # of subarraies of nums[l~r] ended by r
    }
    return res;
  }
};
