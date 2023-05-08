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
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
		// longest non-decreasing subsequence with obstacles[i] as the last one
		// using binary search O(nlogn)
		// greedily replace the upper_bound (equal should be kept)
		vector<int> ans(obstacles.size(), 1);
		vector<int> dp;
		for(int i = 0; i < obstacles.size(); ++i) {
			if(dp.empty()) dp.push_back(obstacles[i]);
			else {
				auto it = upper_bound(dp.begin(), dp.end(), obstacles[i]);
				int pos = it - dp.begin();
				if(it == dp.end())
					dp.push_back(obstacles[i]);
				else *it = obstacles[i];
				ans[i] = pos + 1;
			}
		}
		return ans;
    }
};