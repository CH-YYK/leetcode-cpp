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
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
		map<int, int> mp;
		for(vector<int>& vec : nums1)
			mp[vec[0]] = vec[1];
		for(vector<int>& vec : nums2)
			mp[vec[0]] += vec[1];
		vector<vector<int>> ans;
		for(auto& [k,v] : mp)
			ans.push_back({k, v});
		return ans;
    }
};