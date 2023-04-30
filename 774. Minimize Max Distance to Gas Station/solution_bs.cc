#include <queue>
#include <utility>
#include <vector>
using namespace std;

/* Using binary search to find the maximum distance
 * Set x as the distance computed to test, and get y stations to be inserted, we want y == k
 *  and larger x will result in smaller y
 * if y <= k: increase y, reduce x, r = x
 * else l = x + 1
 */
// more like a bisection problem in Math
class Solution {
public:
  double minmaxGasDist(vector<int> &stations, int k) {
    double l = 0, r = 0;
    for (int i = 1; i < stations.size(); ++i)
      r = max(r, (double)stations[i] - stations[i - 1]);

    while (l + 1e-6 < r) {
      double x = (l + r) / 2;
      int y = 0;
      for (int i = 1; i < stations.size(); ++i) {
        // how many stations can we insert between stations[i] and stations[i-1]
        y += (stations[i] - stations[i - 1]) / x;
      }
      if (y <= k)
        r = x;
      else
        l = x;
    }
    return l;
  }
};
