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
    int maxPoints(vector<vector<int>>& points) {
		// each point could be a starting point
		// a line is defined by two points (starting point and ratio)
		// a ratio can be a pair <x, y> -> k = y / x
		vector<map<pair<int,int>, int>> pivots(points.size());

		int ans = 0;
		for(int i = 1; i < points.size(); ++i) {
			int x2 = points[i][0];
			int y2 = points[i][1];
			for(int j = 0; j < i; ++j) {
				int x1 = points[j][0];
				int y1 = points[j][1];
				int diffy = y2 - y1;
				int diffx = x2 - x1;
				int gcd = __gcd(abs(diffx), abs(diffy));
				if(diffx * diffy > 0)
					diffx = abs(diffx), diffy = abs(diffy);
				else
					diffx = -abs(diffx), diffy = abs(diffy);
				pair<int,int> ratio = {diffx/gcd, diffy/gcd};
				ans = max(ans, ++pivots[i][ratio]);
			}
		}
		return ans + 1;
    }
};