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
    int maxValue(int n, int index, int maxSum) {
    	// [] [l*(l+1)/2 + (l + 1)] [] 
    	// x      2l + 1             y
    	int l = 1, r = maxSum;
    	while(l < r) {
    		long m = l + (r - l + 1) / 2;
    		long sum = getRangeSum(m, n, index);
    		if(sum <= maxSum)
    			l = m;
    		else
    			r = m - 1;
    	}
    	return l;
    }
private:
	long getRangeSum(long val, int n, int index) {
		long leftmin = max(val - index, 1l);
		long rightmin = max(val - (n-index-1), 1l);
		long leftsum = 0, rightsum = 0;
		if(leftmin == 1)
			leftsum += index - val + 1;
		if(rightmin == 1)
			rightsum += n-1 - (index + val - 1);
		leftsum += (leftmin + val) * (val - leftmin + 1) / 2;
		rightsum += (rightmin + val-1) * (val - rightmin) / 2;
		return leftsum + rightsum;
	}
};