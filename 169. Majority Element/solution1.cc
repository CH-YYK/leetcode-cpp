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
    int majorityElement(vector<int>& nums) {
    	// the Boyer-Moore Voting algorithm
    	// it presumes that the majority element (> n/2) must exit
		int cnt = 0, target = -1;
		for(int num : nums) {
			if(cnt == 0) target = num;
			cnt += (num == target) ? 1 : -1;
		}
		return target;
    }
};