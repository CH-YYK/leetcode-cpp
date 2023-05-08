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
    vector<int> distinctDifferenceArray(vector<int>& nums) {
    	// diff[i] := number of distinct elements in nums[i+1:]
    	int n = nums.size();
    	vector<int> diff(n, 0);
    	unordered_set<int> s;
    	for(int i = 0; i < n; ++i) {
    		s.insert(nums[i]);    		
    		diff[i] = s.size();
    	}
    	s.clear();
    	for(int i = n-1; i>=0; --i) {
    		diff[i] -= s.size();
    		s.insert(nums[i]);
    	}
        return diff;
    }
};