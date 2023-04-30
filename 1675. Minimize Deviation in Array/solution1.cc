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
    int minimumDeviation(vector<int>& nums) {
		// if nums[i] is even: nums[i] /= 2
		// if nums[i] is odd: nums[i] *= 2
		// 
		// We can make an even number smaller if it's power of 2
		// but for an odd number, there is only two [nums[i], 2*nums[i]]
		// 
		// An odd number cannot be decreased while an even number can not be increased
		//  -> make odd to evens such that all numbers are maximized
		// 	-> decrease numbers and keep track of the (max - min) at each state.
		// 
		// Greedy analysis: 
		// 	[c > b > a] and curr res is (c - a)
		// 	then [b > a, c/2] must be the best next state, because a,b can not be increased.
		//  though we cannot say for sure that next state would be better.
		priority_queue<int> pq;
		int ans = INT_MAX, min_ = INT_MAX;
		for(int num : nums) {
			if(num % 2 == 0) {
				pq.push(num);
				min_ = min(min_, num);
			} else {
				pq.push(num * 2);
				min_ = min(min_, 2 * num);
			}
		}
		while(!pq.empty()) {
			int curr = pq.top();
			pq.pop();
			ans = min(ans, curr - min_);
			if(curr % 2 == 0) {
				pq.push(curr / 2);
				min_ = min(min_, curr / 2);
			}
			else return ans;
		}
		return ans;
    }
};