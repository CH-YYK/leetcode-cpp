/* Max profit made with at most two trasactions
 * profit([x,y]) maxprofit made in one trasaction from subarray [x,y]
 * Case1: [a,b], [c,d]. profit([a,b]) + profit([c,d])
 * Case2: [a,b], [c,d], [e,f], max(profit[a,d] +  profit[e,f], profit[a,b] + profit[c, f])
 * profit[i] = profit(prices[:i]) + profit(prices[i+1:])
 */
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int leftmin = INT_MAX;
    int rightmax = 0;

    vector<int> leftprofits(n, 0);
    vector<int> rightprofits(n, 0);

    // max profit made from prices[:i] right-inclusive
    for (int i = 0; i < n; ++i) {
      leftmin = min(prices[i], leftmin);
      if (i > 0)
        leftprofits[i] = max(leftprofits[i - 1], prices[i] - leftmin);
    }
    // max profit made from prices[i:]
    for (int i = n - 1; i >= 0; --i) {
      rightmax = max(prices[i], rightmax);
      if (i < n - 1)
        rightprofits[i] = max(rightprofits[i + 1], rightmax - prices[i]);
    }

    // max profit at i leftprofits[i] + rightprofits[i+1]
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (i < n - 1)
        res = max(leftprofits[i] + rightprofits[i + 1], res);
      else
        res = max(leftprofits[i], res);
    }
    return res;
  }
};
