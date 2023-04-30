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
    int maxSubarraySumCircular(vector<int>& nums) {
    	// max(subarray sum, spacial sum)
    	// spacial sum can be seen as max(prefix + suffix)
    	// max(prefix + suffix) = sum - min(subarray sum);
    	// Use Kadane's Algorithm
    	int curmax = INT_MIN, curmin = INT_MAX, sum = 0;
    	int maxsum = INT_MIN, minsum = INT_MAX;
    	for(int num : nums) {
    		curmax = max(curmax, 0) + num;
    		curmin = min(curmin, 0) + num;
    		maxsum = max(maxsum, curmax);
    		minsum = min(minsum, curmin);
    		sum += num;
    	}
    	return sum == minsum ? maxsum : max(maxsum, sum - minsum);
    }
};