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
    int findMinMoves(vector<int>& machines) {
		// number of dresses that will go through machines[i]
		// [1, 0, 5] -> [1, 2, -3] -> [1,3,0]
		// [1,0,4,0,5] -> [1,2,-2,2,-3]->[1,3,1,3,0]
		// 
		// Note that: don't over-understand the logic here
		// 	it's CHOOSING m machines instead of CHOOSING a range of machines
		// The minium number of moves is the maximum number of necessary operations on every machine.
		// L > 0 && R > 0: both sides lacks dresses, and we can only export one dress from current machines at a time, so result is abs(L) + abs(R)
		// L < 0 && R < 0: both sides contains too many dresses, and we can import dresses from both sides at the same time, so result is max(abs(L), abs(R))
		// L < 0 && R > 0 or L >0 && R < 0: the side with a larger absolute value will import/export its extra dresses from/to current machine or other side, so result is max(abs(L), abs(R))
		int prefix = 0;
		int ans = 0;
		int sum = accumulate(machines.begin(), machines.end(), 0);
		int n = machines.size();
		if(sum % n > 0) return -1;
		
		int target = sum / n;
		vector<int> leftSum(n, 0), rightSum(n, 0);

		for(int i = 1; i < n; ++i) 
			leftSum[i] = leftSum[i-1] + machines[i-1];
		for(int i = n - 2; i >=0; --i)
			rightSum[i] = rightSum[i+1] + machines[i+1];

		// for a given index i, the clothes flood from its right
		// side to its left side or vice versa.
		// 
		for(int i = 0; i < n; ++i) {
			int left = 0, right = 0;
			left = max(i * target - leftSum[i], 0);
			right = max((n - i - 1) * target - rightSum[i], 0);
			ans = max(ans, left + right);
		}
		return ans;
    }
};