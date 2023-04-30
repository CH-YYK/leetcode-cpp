#include <vector>
#include <unordered_map>
using namespace std;

/* Problem can become a classical problem if it is asking "number of subarrays with at most K distinct elements"
 * When we get a window [l,r] containing exactly K distince elements, each subarray of it will contribute 1 count, r - l + 1
 * window state: hashmap
 */
class Solution {
public:
  int subarraysWithKDistinct(vector<int> &A, int K) {
    return atmost(A, K) - atmost(A, K - 1);
  }

private:
  int atmost(vector<int> &A, int K) {
    unordered_map<int, int> m;
    int l = 0, res = 0;
    for (int r = 0; r < A.size(); ++r) {
      m[A[r]]++;
      while (m.size() > K) {
        if (--m[A[l]] == 0)
          m.erase(A[l]);
        l++;
      }
      res += r - l + 1;
    }
    return res;
  }
};
