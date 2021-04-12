#include <vector>
#include <cmath>
using namespace std;

/* Find correct layer i: O(log(sqrt(MN)))
 *
 * Find (k - (i+1)^2)-th smallest in the layer: O(log(M+N))
 */
class Solution {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int n = matrix.size();
    int l = 0, r = n - 1, m;
    while(l < r) {
      m = (l + r) / 2;
      if((m+1) * (m+1) >= k) r = m - 1;
      else if((m+1) * (m+1) < k) l = m + 1;
    } // l is the layer index

    k -= (l+1) * (l+1);

    int i = 0, j = 0;
    int imin = 0, imax = k-1;
    while(imin < imax) {
      i = (imin + imax) / 2;
      j = k- i-1;
      if(matrix[l][i] < matrix[j-1][l]) imin = i + 1;
      else if(i > 0 && matrix[l][i-1] > matrix[j][l]) imax = i-1;
      else return min(matrix[l][i], matrix[j][l]);
    }
    return min(matrix[l][imin], matrix[k-1-imin][l]);
  }
};
