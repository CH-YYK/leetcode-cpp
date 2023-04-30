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
#include <cmath>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		// cheapest price from src to dst with k stops
		// *global optimization doesn't require local optimization*
		if(src == dst) return 0;
		vector<unordered_map<int, int>> graph(n);
		for(vector<int>& flight : flights) 
			graph[flight[0]][flight[1]] = flight[2];

		queue<pair<int,int>> pq; // <price, stop>
		pq.emplace(0, src);

		// one-single visited vector is not good because we 
		// might have to re-visit a node. We stop re-visiting
		// a node only when the there is "late arrive" with "larger price"
		// We can either use a K*N matrix to track both step and price,
		// but if we fixed the step round-by-round, we only need a 1-d vector
		// for prices
		vector<int> prices(n, INT_MAX);
		prices[src] = 0;

        int ans = INT_MAX;
        // k stops internal -> k+1 steps in total
		while(!pq.empty() && k >= 0) {
			k--;			
			int size = pq.size();
			while(size--) {
				auto [price, curr] = pq.front();
				pq.pop();
				for(auto [nxt, p] : graph[curr]) {
					// it's already re-visit, 
					// skip if the price is high
					if(price + p >= prices[nxt])
						continue;
            	    prices[nxt] = price + p;
                	if(nxt == dst)
                    	ans = min(ans, price + p);
					pq.emplace(price + p, nxt);
				}
			}
		}
		return ans == INT_MAX ? -1 : ans;
    }
};