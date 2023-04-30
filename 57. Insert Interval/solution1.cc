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

/*		99
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    	bool used = 0;
		vector<vector<int>> ans;
		for(int i = 0; i < intervals.size(); ++i) {
			vector<int> interval = intervals[i];
			if(interval[1] < newInterval[0])
				ans.push_back(intervals[i]);
			else if(interval[0] > newInterval[1])
				ans.push_back(intervals[i]);
			else {
				if(used) {
					ans.back()[1] = max(ans.back()[1], interval[1]);
				} else {
					ans.push_back({min(interval[0], newInterval[0]), 
						max(interval[1], newInterval[1])})
					used = 1;
				}
			}
		}
		return ans;
    }
};