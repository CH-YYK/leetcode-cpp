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
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
		// max(chargeTimes) + k * sum(runningTimes)        
		// sliding window: [l, r]
		// require: get the max(chargeTimes) on the fly
    	deque<int> dq;
    	int l = 0, n = chargeTimes.size(), ans = 0;
    	long sum = 0;
    	for(int r = 0; r < n; ++r) {
    		while(!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[r])
    			dq.pop_back();
    		dq.push_back(r);
    		sum += runningCosts[r];
    		int maxCharge = chargeTimes[dq.front()];
    		while(l <= r && sum * (r - l + 1) + maxCharge > budget) {
    			if(dq.front() == l) dq.pop_front();
    			sum -= runningCosts[l];
    			l++;
    		}
            ans = max(ans, r - l + 1);
    	}
    	return ans;
    }
};