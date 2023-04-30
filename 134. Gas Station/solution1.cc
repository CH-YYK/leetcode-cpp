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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // find a good place to get start
        // cumulative gas should always be > 0 
        int n = gas.size();
        vector<int> diff(n), presum(n + 1, 0);
        int sum = 0;
        for(int i = 0; i < n; ++i) {
        	diff[i] = gas[i] - cost[i];
			sum += diff[i];
        }
        if(sum < 0) return -1;
        int l = 0;
        while(l < n) {
        	int r = l;
        	int cumsum = 0;
        	while(r < n && cumsum + diff[r] >= 0) {
        		cumsum += diff[r];
        		r++;
        	}
        	if(r == n) return l;
        	l = r + 1;
        }
        return -1;
    }
};