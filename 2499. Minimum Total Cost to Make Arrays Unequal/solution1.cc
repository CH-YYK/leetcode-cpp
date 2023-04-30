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
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
		// Greedy + majority problem
		// 
		// at least: the cost is sum of i that nums1[i] == nums2[i]
		// 	the exception:
		// 		one value of nums1[i] is predominant to be swapped internally
		// When the exception happens, we need borrow numbers from others
		// 	
		// If exception-1 happens, use min(i + j) for all i that nums1[i] == nums2[i]
		// If exception-2 happens, use min(i + j) for i (smallest index)


    	// find the majority nums1[i] == nums2[i], and total counts
    	vector<int> removals;
    	unordered_map<int,int> freq;
    	long long ans = 0;
    	int cnt = 0, num = -1, size = 0;
    	for(int i = 0; i < nums1.size(); ++i){
    		if(nums1[i] == nums2[i]) {
    			size++;
    			ans += i;

    			freq[nums1[i]]++;
	    		
	    		if(cnt == 0) num = nums1[i];
	    		cnt += num == nums1[i] ? 1 : -1;
    		}
    	}

    	// is there any predominant value
    	if(freq[num] > size / 2) {
    		// no outside value to swap with
    		if(size == nums1.size()) return -1;
    		for(int i = 0; i < nums1.size(); ++i) {
    			if(nums1[i] != nums2[i] && nums1[i] != num && nums2[i] != num && cnt) {
    				ans += i, cnt--;
    			}
    		}
    		// no suitable value was found to swap with
            if(cnt > 0) return -1;
    	}
    	return ans;
    }
};