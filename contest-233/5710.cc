#include <map>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int getNumberOfBacklogOrders(vector<vector<int>> &orders) {
    // buy_price >= sell_price
    // buy_order , decreasing
    // sell_order, increasing
    map<int, long, greater<int>> buyorders;
    map<int, long> sellorders;

    for(auto p : orders) {
      if(p[2] == 0) {  // buy
        if(sellorders.empty() || p[0] < sellorders.begin()->first)
          buyorders[p[0]] += p[1];
        else {
          while(p[1] && !sellorders.empty() && p[0] >= sellorders.begin()->first) {
            auto it = sellorders.begin();  // proper sell orders, sellprice <= p[0]
            int tmp = it->second;
            if(tmp > p[1]) {
              tmp -= p[1], p[1] = 0;
              sellorders[it->first] = tmp;
            } else {
              p[1] -= tmp, tmp = 0;
              sellorders.erase(it->first);
            }
          }
            if(p[1]) buyorders[p[0]] += p[1];
        }
      } else {  // sell
        if(buyorders.empty() || p[0] > buyorders.begin()->first)
          sellorders[p[0]] += p[1];
        else {
          while (p[1] && !buyorders.empty() && p[0] <= buyorders.begin()->first) {
            auto it = buyorders.begin(); // proper buy orders, buyprice >= p[0]
            int tmp = it->second;
            if (tmp > p[1]) {
              tmp -= p[1], p[1] = 0;
              buyorders[it->first] = tmp;
            } else {
              p[1] -= tmp, tmp = 0;
              buyorders.erase(it->first);
            }
          }
            if(p[1]) sellorders[p[0]] += p[1];
        }
      }
    }
    int res = 0;
    for(auto p : buyorders) { 
        res += p.second;
        res %= 1000000007;
    }
    for(auto p : sellorders)  {
        res += p.second;
        res %= 1000000007;
    }
    return res % 1000000007; // sum of buyorders and sellorders
  }
};
