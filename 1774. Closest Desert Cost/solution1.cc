/* Check all combinations O(3 ^ N * M)
 *   - M: size of costs
 *   - N: size of toppings
 */
class Solution {
public:
  int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
    _target = target;
    for(int i = 0; i < baseCosts.size(); ++i) 
      getWholeCost(baseCosts[i], 0, baseCosts, toppingCosts);
    return res;
  }
private:
  int eps = INT_MAX;  // track best one so far
  int res = INT_MAX;  // best result so far
  int _target;

  void getWholeCost(int currentCost, int toppingId, vector<int>& baseCosts, vector<int>& toppingCosts) {
    if(toppingId == toppingCosts.size()) {
      if(abs(currentCost - _target) < eps) {
        eps = abs(currentCost - _target);
        res = currentCost;
      } else if(abs(currentCost - _target) == eps)
        res = min(currentCost, res);  // handle multiple equal results
      return;
    }
    getWholeCost(currentCost,  toppingId + 1, baseCosts, toppingCosts);
    getWholeCost(currentCost + 1 * toppingCosts[toppingId], toppingId + 1, baseCosts, toppingCosts);
    getWholeCost(currentCost + 2 * toppingCosts[toppingId], toppingId + 1, baseCosts, toppingCosts);
  }
};
