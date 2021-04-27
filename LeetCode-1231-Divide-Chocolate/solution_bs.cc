#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/* Brute force: more sweetness I want will result in less bars of chocolate
 * Binary Search: x sweetness will result in y bars of chocolate, increase x will reduce y
 *  if y >= k+1: (x is possible) reduce y, l = x
 *  if y < k + 1: increase y: reduce x, r = x - 1
 */
class Solution {
public:
  int maximizeSweetness(vector<int> &sweetness, int K) {
    int l = *min_element(sweetness.begin(), sweetness.end());
    int r = accumulate(sweetness.begin(), sweetness.end(), 0);

    while (l < r) {
      int x = (l + r + 1) / 2;  // handle dead loop
      int y = 0, sum = 0, minsw = 1e9;
      // y refer to the number of partitions we have filled
      // and we are currently at (y+1)th partition
      for (int i = 0; i < sweetness.size(); ++i) {
        sum += sweetness[i];
        if (sum >= x)  // we close

          y++, sum = 0;
      }
      if (y >= K + 1)
        l = x;
      else
        r = x - 1;
    }
    return l;
  }
};
