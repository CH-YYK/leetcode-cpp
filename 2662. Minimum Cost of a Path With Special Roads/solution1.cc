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
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        // visit all 200 roads + target = 201 nodes per step during traversing
        // Dijkstra Algorithm
        map<pair<int,int>, int> distance;
        // maxheap
        priority_queue<array<int, 3>, vector<array<int,3>>, greater<array<int, 3>>> pq;
        pq.push({0, start[0], start[1]});
        distance[{start[0], start[1]}] = 0;
        distance[{target[0], target[1]}] = getDist(start[0], start[1], target[0], target[1]);

        while(!pq.empty()) {
        	array<int, 3> curr = pq.top();
        	pq.pop();
        	int cost = curr[0];
        	int currx = curr[1];
        	int curry = curr[2];

        	// distance to the target directly
        	int targetdist = cost + getDist(currx, curry, target[0], target[1]);
        	if(targetdist < distance[{target[0], target[1]}])
        		distance[{target[0], target[1]}] = targetdist;

        	for(auto& road : specialRoads) {
        		int x1 = road[0], y1 = road[1];
        		int x2 = road[2], y2 = road[3];
        		// go to (x2, y2) via a special road
        		int d = cost + getDist(currx, curry, x1, y1) + road[4];
                if(distance.count({x2, y2}) && d >= distance[{x2, y2}]) continue;
        		distance[{x2, y2}] = d;
        		pq.push({d, x2, y2});
        	}
        }
        return distance[{target[0], target[1]}];
    }
private:
	int getDist(int x1, int y1, int x2, int y2) {
		return abs(x1 - x2) + abs(y1 - y2);
	}
};