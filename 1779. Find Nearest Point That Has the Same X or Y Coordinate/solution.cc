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

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        function<int(vector<int>&)> dist = [&](vector<int>& point) {
        	return abs(point[0] - x) + abs(point[1] - y);
        };
        int min_ = INT_MAX;
        int idx = -1;
        for (int i = 0; i < points.size(); ++i) {
        	int distance = dist(points[i]);
        	if(!(x == points[i][0] || y == points[i][1]))
        		continue;
        	if(distance < min_)
        		idx = i, min_ = distance;        	
        }
        return idx;
    }
};

int main() {
    
}
