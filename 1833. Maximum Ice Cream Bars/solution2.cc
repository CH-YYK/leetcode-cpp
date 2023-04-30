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
    int maxIceCream(vector<int>& costs, int coins) {
    	int max = *max_element(costs.begin(), costs.end());
    	vector<int> freq(max + 1, 0);
    	for(int cost : costs)
    		freq[cost]++;
    	int ans = 0;
    	for(int cost = 1; cost <= max; ++cost) {
    		if(freq[cost] == 0) continue;
    		if(coins < cost) break;
    		int num = min(coins / cost, freq[cost]);
    		coins -= num * cost;
    		ans += num;
    	}
    	return ans;
    }
};