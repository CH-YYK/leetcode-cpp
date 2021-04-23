class Solution {
public:
  int maxIceCream(vector<int> &costs, int coins) {
    sort(costs.begin(), costs.end());
    int res = 0;
    for(int c : costs) {
      if(coins - c >= 0) res++, coins -= c;
      else return res;
    }
    return res;
  }
};
