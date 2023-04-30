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
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    	int n = capacity.size();
    	vector<int> diff(n);
    	for(int i = 0; i < n; ++i) 
    		diff[i] = capacity[i] - rocks[i];
    	sort(diff.begin(), diff.end());
    	vector<long> presum(n + 1, 0);
    	for(int i = 0; i < n; ++i)
    		presum[i + 1] = presum[i] + diff[i];
    	auto it = upper_bound(presum.begin(), presum.end(), additionalRocks);
    	return it - presum.begin() - 1; 
    }
};