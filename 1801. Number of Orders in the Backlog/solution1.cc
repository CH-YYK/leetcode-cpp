// Hello, this is a CPP leetcode snippet.

#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <set>
#include <map>
#include <sstream>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/


class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    	// buy backlog
        priority_queue<pair<int,int>> buys;  // max heap <price, amount>
        priority_queue<pair<int,int>> sells; // min heap <-price, amount>
        long nBuys = 0, nSells = 0;
        int mod = 1e9 + 7;
        for(vector<int>& order: orders) {
        	if(order[2] == 0) {
        		// buys
        		if(sells.empty()) {
        			buys.emplace(order[0], order[1]);
        			nBuys = (nBuys + order[1]) % mod;
        			continue;
        		}
        		while(!sells.empty() && -sells.top().first <= order[0] && order[1] > 0) {
        			auto [np, num] = sells.top();
        			sells.pop();
        			nSells = (nSells + mod - min(order[1], num)) % mod;
        			if(num > order[1]) {
        				num -= order[1];
                        order[1] = 0;
                    }else {
        				order[1] -= num;
        				num = 0;
        			}
        			if(num > 0) 
        				sells.emplace(np, num);        			
        		}
       			if (order[1] > 0) {
       				buys.emplace(order[0], order[1]);
       				nBuys = (nBuys + order[1]) % mod;
       			}
        	} else {
        		// sells
        		if(buys.empty()) {
        			sells.emplace(-order[0], order[1]);
        			nBuys = (nBuys + order[1]) % mod;
        			continue;
        		}
        		while(!buys.empty() && buys.top().first >= order[0] && order[1] > 0) {
        			auto [p, num] = buys.top();
        			buys.pop();
					nBuys = (nBuys + mod - min(order[1], num)) % mod;
        			if(num > order[1]) {
        				num -= order[1];
                        order[1] = 0;
                    } else {
        				order[1] -= num;
        				num = 0;
        			}			
        			if(num > 0)
        				buys.emplace(p, num);
        		}
        		if(order[1] > 0) {
        			sells.emplace(-order[0], order[1]);
        			nSells = (nSells + order[1]) % mod;
        		}
        	}
        }
        return (nSells + nBuys) % mod;
    }
};