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
    int findMinArrowShots(vector<vector<int>>& points) {
        // every balloon should be bursted
        // the needle is just a value
        // -> find the number of non-overlapping intersections
        // 
        // an intersection is "max left and minimum right"
        // basically, we are only interested in the right bar if sorting by left bar
        sort(points.begin(), points.end());
        int ans = 0;
        int right = -1;

        for(vector<int>& point : points) {
        	if(right = -1) {
        		ans++;
        		right = point[1];
        	} else {
        		if(point[0] <= right)
        			right = min(right, point[1]);
        		else
        			right = point[1], ans++;
        	}
        }
        return ans;
    }
};