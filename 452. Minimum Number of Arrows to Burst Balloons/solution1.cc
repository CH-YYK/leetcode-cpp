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
        sort(points.begin(), points.end());
        vector<pair<int,int>> intersections;

        for(vector<int>& point : points) {
        	if(intersections.empty()) {
        		intersections.emplace_back(point[0], point[1]);
        	} else {
        		if(point[0] <= intersections.back().second)
        			intersections.back().second = min(intersections.back().second, point[1]);
        		else
        			intersections.emplace_back(point[0], point[1]);
        	}
        }
        return intersections.size();
    }
};