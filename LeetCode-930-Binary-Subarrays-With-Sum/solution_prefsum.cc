#include <vector>
#include <unordered_map>

using namespace std;

/* prefix sum: Sl and Sh
 * Given a Sh, find number of Sl st Sh - S == Sl
 */
class Solution {
public:
  int numSubarraysWithSum(vector<int> &A, int S) {
    unordered_map<int,int> m;
    vector<int> presum(A.size() + 1, 0);
    for(int i = 0; i < A.size(); ++i)
      presum[i + 1] = presum[i] + A[i];
    int res = 0;
    for(int num : presum) {
      res += m[num - S];
      m[num]++;
    }
    return res;
  }
};
