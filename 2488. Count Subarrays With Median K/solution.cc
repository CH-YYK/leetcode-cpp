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

using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
    	// the integers in the array are distinct so the subarrays must be around k    	
    	// If a subarray has median as k.
    	//   then there must be Count(num > k) - Count(num < k) = 1 or 0
    	// If nums[i] > k -> 1, If nums[i] < k -> -1, 
    	//    prefix_sum of this (-1, 1) array
    	// find the number of pairs in this prefix_sums s.t
    	//  prefix_sum[i] - prefix_sum[j] = 0 || 1 -> [j: i] should be counted
    	// 
    	// The problem is deduced to a 2Sum    
    	//  To ensure k is in the subarray, stop putting into map after visiting k
    	int balance = 0, foundK = 0;
    	unordered_map<int, int> cnts;
    	cnts[0] = 1;
    	int ans = 0;

		for(int num : nums) {
    		if(num < k) balance--;
    		if(num > k) balance++;
    		if(num == k) foundK = 1;

    		if(foundK) {
    			ans += cnts[balance] + cnts[balance - 1];
    		} else {
    			cnts[balance]++;
    		}
		}
		return ans;
    }
};
int main() {
    
}
