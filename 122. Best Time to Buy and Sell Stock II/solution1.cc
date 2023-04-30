
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if(prices.empty()) return 0;
    int res = 0;
    int prev = prices[0];
    for(int curr : prices) {
      if(curr >= prev) res += curr - prev;
      prev = curr;
    }
    return res;
  }
};
